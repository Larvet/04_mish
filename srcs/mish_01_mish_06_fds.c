/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_06_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 15:48:36 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_fds_malloc(t_mish *mish)
{
	int	i;

	mish->fds = malloc((mish->nb + 1) * sizeof(int *));
	if (mish->fds == NULL)
		return (mish_error_add(mish, err_malloc, errno, "mish->fds == NULL"));
	i = -1;
	while (++i < mish->nb + 1)
	{
		(mish->fds)[i] = malloc(2 * sizeof(int));
		if ((mish->fds)[i] == NULL)
			return (mish_error_add(mish, err_malloc, errno, "fds[i] == NULL"));
		(mish->fds)[i][0] = -1;
		(mish->fds)[i][1] = -1;
	}
	return (0);
}

void	mish_fds_close(t_mish *mish)
{
	int	i;

	i = -1;
	while (++i < (mish->nb + 1))
	{
		if (mish->fds && (mish->fds)[i])
			close_reset_fd(((mish->fds)[i]));
		if (mish->fds && (mish->fds)[i] + 1)
			close_reset_fd((mish->fds[i] + 1));
	}
}

void	mish_fds_free(t_mish *mish)
{
	int	i;

	i = -1;
	while (++i < mish->nb + 1)
		if (mish && mish->fds && (mish->fds)[i])
			free((mish->fds)[i]);
	if (mish && mish->fds)
	{
		free(mish->fds);
		mish->fds = NULL;
	}
}

void	mish_fds_print(t_mish *mish)
{
	int	i;

	if (mish->fds)
	{
		i = 0;
		while (i < mish->nb && (mish->fds)[i])
		{
			printf("%i > %i\n", (mish->fds)[i][0], (mish->fds)[i][1]);
			i++;
		}
	}
	else
		printf("(null)\n");
}
