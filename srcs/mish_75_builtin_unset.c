/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_75_builtin_unset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:15:25 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"
/*
	si va[1][0] == '-'
		bash: unset: -a: invalid option
	
	unset "invalid-variable-name"  # Cela provoquera une erreur

*/

/* export with no options */
void	builtin_unset(t_process *p)
{
	int		i;

	if (t_process_is_invalid_option(p))
		return;
	i = 0;
	while(++i < p->ac)
		mish_env_remove(p->mish, p->av[i]);
	//p->exitstatus = 0;
	mish_exit_status_set(p->mish ,0);
}
