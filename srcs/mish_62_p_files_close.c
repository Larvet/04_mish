/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_62_p_files_close.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:08:03 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_process_close_iofile(t_process *p)
{
	t_file	*tfile;

	tfile = p->iofiles;
	while (tfile)
	{
		if (tfile->fd > 2)
			close_reset_fd(&(tfile->fd));
		tfile = tfile->next;
	}
}

void	mish_heredocs_unlink(t_mish *mish)
{
	t_process	*p;
	t_file		*tfile;
	int			i;

	i = -1;
	while( ++i < mish->nb && ((mish->p) + i))
	{
		p = (mish->p) + i;
		tfile = p->iofiles;
		while(tfile)
		{
			if (tfile->type == tf_ifile_heredoc && tfile == p->infile)
				if(unlink(tfile->path) != 0)
					perror("minishell: file deleting error :");
			tfile = tfile->next;
		}
	}
}

void	mish_p_iofiles_close(t_mish *mish)
{
	int	i;

	i = -1;
	while (++i < mish->nb)
		t_process_close_iofile((mish->p) + i);
}
