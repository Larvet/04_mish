/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_54_process_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:17:07 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:01:58 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	close_reset_fd(int *fd)
{
	if (fd && *fd > 2)
	{
		//fprintf(stderr, "close_reset_fd %i\n", *fd); //TEST
		close(*fd);
		*fd = -1;
	}
}

t_err_type	t_process_pipe_fds(t_process *process)
{
	int		i;
	t_mish	*mish;

	i = process->index;
	mish = process->mish;
	if (i == 0)
	{
		if (pipe((mish->fds)[0]) == -1)
			return (mish_error_add(mish, err_pipe, errno, "pipe 0 == -1"));
	}
	else
	{
		close_reset_fd((mish->fds)[i - 1] + 0);
		close_reset_fd((mish->fds)[i - 1] + 1);
	}
	if (pipe((mish->fds)[i + 1]) == -1)
		return (mish_error_add(mish, err_pipe, errno, "pipe index == -1"));
	return (0);
}

t_err_type	t_process_dup_io(t_process *p)
{
	if (p->infile->fd < 3)
	{
		if (p->index != 0)
			if (dup2((p->mish->fds)[p->index][0], STDIN_FILENO) == -1)
				mish_error_add(p->mish, err_dup2, errno, "dup2[i][0]");
	}
	else
	{
		if (dup2(p->infile->fd, STDIN_FILENO) == -1)
			mish_error_add(p->mish, err_dup2, errno, "dup2 fd_in");
		//p->infile->fd = -1;
		close_reset_fd(&(p->infile->fd));
	}
	if (p->outfile->fd < 3)
	{
		if (p->index != p->mish->nb - 1)
			if (dup2((p->mish->fds)[p->index + 1][1], STDOUT_FILENO) == -1)
				mish_error_add(p->mish, err_dup2, errno, "dup2[i][1]");
	}
	else
	{
		if (dup2(p->outfile->fd, STDOUT_FILENO) == -1)
			mish_error_add(p->mish, err_dup2, errno, "dup2 fd_out");
		//p->outfile->fd = -1;
		close_reset_fd(&(p->outfile->fd));
	}
	mish_p_iofiles_close(p->mish);
	mish_fds_close(p->mish);
	return (0);
}

t_err_type	t_process_dup_io_builtin(t_process *p)
{
	int tmp;

	if (p->infile->fd > 2)
	{
		p->fdinbkp = dup(STDIN_FILENO);
		if (p->fdinbkp == -1)
			return (mish_error_add(p->mish, err_dup2, errno, "dup fd_in"));
		tmp = dup2(p->infile->fd, STDIN_FILENO);
		if (tmp == -1)
			return (mish_error_add(p->mish, err_dup2, errno, "dup2 fd_in"));
		close_reset_fd(&(p->infile->fd));
	}	
	if (p->outfile->fd > 2)
	{
		p->fdoutbkp = dup(STDOUT_FILENO);
		if (p->fdoutbkp == -1)
			return (mish_error_add(p->mish, err_dup2, errno, "dup fd_out"));
		tmp = dup2(p->outfile->fd, STDOUT_FILENO);
		if (tmp == -1)
			return (mish_error_add(p->mish, err_dup2, errno, "dup2 fd_out"));
		close_reset_fd(&(p->outfile->fd));
	}
	mish_p_iofiles_close(p->mish);
	return (0);
}
