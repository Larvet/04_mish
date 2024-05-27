/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_71_builtin_echo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:12:54 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"
#include "limits.h"

/* "-n nnnnn" -> 1 string (av[0]) */
static int	is_flag(char *str)
{
	int	i;

	i = 1;
	while (str && str[0] == '-'
			&& str[i] == 'n')
		i++;
	return (i > 1 && !str[i]);
}

static char	*set_endl(char *str)
{
	char	*endl;

	if (is_flag(str))
		endl = ft_strdup("");
	else
		endl = ft_strdup("\n");
	return (endl);
}

static char	**set_to_print(char **av, char *endl)
{
	char			**dst;

	if (!*endl)
		dst = strtab_addstr(&av[2], endl);
	else
		dst = strtab_addstr(&av[1], endl);
	return (dst);
}

void	builtin_echo(t_process *process)
{
	char	**to_print;
	char	*endl;

	to_print = NULL;
	if (process && process->av)
	{
		endl = set_endl(process->av[1]);
		if (endl)
		{
			to_print = set_to_print(process->av, endl);
			if (to_print)
			{
				strtab_print(to_print, " ");
				free(to_print);
			}
			free(endl);
		}
	}
	//	process->exitstatus = 0;
	mish_exit_status_set(process->mish ,0);
}
