/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_76_builtin_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:15:32 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/* env with no options or arguments */
void	builtin_env(t_process *process)
{
	if (t_process_is_invalid_option(process))
		return;
	t_env_print(process->mish->env);
	//process->exitstatus = 0;
	mish_exit_status_set(process->mish ,0);
}
