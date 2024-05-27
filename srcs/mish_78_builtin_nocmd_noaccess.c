/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_78_builtin_nocmd_noaccess.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:35:06 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/* empty cmd with no args */
void	builtin_no_cmd(t_process *process)
{
	(void) process;
	//mish_exit_status_set(process->mish ,0);
}

/* minishell: Command 'p->cmd' not found */
void	builtin_no_access_cmd(t_process *process)
{
	char	*str;

	str = ft_strjoin(process->av[0], ": command not found\n");
	if (str)
	{
		builtin_error(process, str, 127);
		free(str);
	}
}
