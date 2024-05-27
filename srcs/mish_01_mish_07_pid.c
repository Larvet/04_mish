/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_07_pid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/05/09 16:12:31 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_pid_malloc(t_mish *mish)
{
	if (mish->nb > 0)
	{
		mish->pid = ft_calloc(mish->nb, sizeof(int));
		if (mish->pid == NULL)
			return (mish_error_add(mish, err_malloc, errno, "pid malloc"));
	}
	return (0);
}

void	mish_pid_print(t_mish *mish)
{
	int	i;

	if (mish && mish->pid)
	{
		printf("(");
		i = -1;
		while (++i < mish->nb)
		{
			printf("%i ", (mish->pid)[i]);
			if (i == mish->nb - 1)
				printf(")\n");
			else
				printf(",");
		}
	}
	else
		printf("(null)\n");
}
