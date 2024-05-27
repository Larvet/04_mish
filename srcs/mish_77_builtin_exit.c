/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_77_builtin_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/23 15:24:30 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void static	mish_error_add_exit(t_mish *mish)
{
	if(mish->nb == 1)
	{
		write (1, "exit\n", ft_strlen("exit\n"));
		mish_error_add(mish, err_exit, 0, "exit");
	}
}

/* exit with no options */
void	builtin_exit(t_process *process)
{
	char *str;

	if (process->ac == 1) // exit
		mish_error_add_exit(process->mish);
	else if(ft_isstr_longlong(process->av[1]))
	{
		if (process->ac == 2) // exit 42
		{
			mish_exit_status_set(process->mish ,ft_atoll(process->av[1]) % 256);
			mish_error_add_exit(process->mish);
		}
		else // exit 42 1 ou // exit 42 a
			builtin_error(process, "bash: exit: too many arguments\n", 1);
	}
	else
	{
		mish_error_add_exit(process->mish);
		str = ft_strjoinva("minishell: exit: ", process->av[1], ": numeric argument required\n", NULL);
		if (str)
		{
			builtin_error(process, str, 2);
			free (str);
		}
		// write(2, "bash: exit: numeric argument required\n", 39);
		// mish_exit_status_set(process->mish ,2);
	}
}

/*
si ac == 1
	fontionnne et retourne 0

sinon si arg 1 est un entier

	si ac == 2
	on prend sa valeur %256 de > 0 a 256
	si n negatif ret = 256 - n % 256)
	fontionnne et retourne le bon n

	si ac > 2
	bash: exit: too many arguments
	ne fonctionne pas

sinon si arg 1 n est pas un entier

	bash: exit: a: numeric argument required
	fonctionnne qd meme
	exstat = 2

		si arg 1 entier 
		si 1 argument n est pas un chiffre alors ne marche pas
		bash: exit: too many arguments
*/