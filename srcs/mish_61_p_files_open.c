/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_61_p_files_open.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:38:59 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	mish_open_iofiles(t_mish *mish)
{
	int	err;
	int	i;

	err = 0;
	i = -1;
	while (++i < mish->nb)
	{
		//t_process_iofile_print(mish->p + i); //TEST
		err += t_process_open_heredoc(mish->p + i, 1);
	}
	i = -1;
	while (++i < mish->nb)
	{
		//t_process_iofile_print(mish->p + i); //TEST
		err += t_process_open_iofiles(mish->p + i);
	}
	i = -1;
	while (++i < mish->nb)
	{
		t_process_inoutfile_get(mish->p + i);
		t_process_iofile_close_unused_fds(mish->p + i);
		//t_process_iofile_print(mish->p + i); //TEST
	}
	
}

int	t_process_open_heredoc(t_process *p, int openfile)
{
	t_file	*tfile;
	int		err;

	err = 0;
	tfile = p->iofiles;
	while (tfile && (err == 0)) //mish_continue(p->mish) &&
	{
		if (tfile->type == tf_ifile_heredoc)
		{
			if (openfile == 1)
				err += t_file_heredoc(tfile, 1, p);
			else
				err += t_file_heredoc(tfile, 0, p);
		}
		tfile = tfile->next;
	}
	return (err);
}

int	t_process_open_iofiles(t_process *p)
{
	t_file	*tfile;
	int		err;

	err = 0;
	tfile = p->iofiles;
	while (tfile && mish_continue(p->mish) && (err == 0))
	{
		if (tfile->type == tf_ifile_rdonly || tfile->type == tf_ofile_creat || \
		tfile->type == tf_ofile_append)
		{
			if (tfile->type == tf_ifile_rdonly)
				tfile->fd = open(tfile->path, O_RDONLY);
			else if (tfile->type == tf_ofile_creat)
				tfile->fd = open(tfile->path, O_RDWR | O_CREAT | O_TRUNC, 0644);
			else if (tfile->type == tf_ofile_append)
				tfile->fd = open(tfile->path, O_RDWR | O_CREAT | O_APPEND, 0644);
			if (tfile->fd == -1)
				err += t_process_iofiles_error(p, errno, tfile->path);
			//else if (tfile != p->infile && tfile != p->outfile)
			//	close_reset_fd(&(tfile->fd));
		}
		tfile = tfile->next;
	}
	return (err);
}


/*
revoir l ouverture
faire l ensemble des here docs
puis
faire l enseble des ouverture tant que ca marche sinon exit.
faire la boucle des ouverture dans iofileopen et traiter les sorties
*/

/*
void	mish_open_iofiles(t_mish *mish)
{
	int	err;
	int	i;

	err = 0;
	i = -1;
	while (++i < mish->nb)
		t_process_open_heredoc(mish->p + i, 1);
	i = -1;
	while (++i < mish->nb)
		t_process_open_iofiles(mish->p + i, &err);		
	// i = -1;
	// while (++i < mish->nb)
	// 	t_process_iofile_print(mish->p + i);	
}

void	t_process_open_heredoc(t_process *p, int openfile)
{
	t_file	*tfile;

	tfile = p->iofiles;
	while (tfile && mish_continue(p->mish))
	{
		if (tfile->type == tf_ifile_heredoc)
		{

			if (openfile == 1 && tfile == t_process_iofile_get(p, 0))
				t_file_heredoc(tfile, 1, p->mish);
			else
				t_file_heredoc(tfile, 0, p->mish);
		}
		tfile = tfile->next;
	}
}

void	t_process_open_iofiles(t_process *p, int *err)
{
	t_file	*tfile;

	tfile = p->iofiles;
	while (tfile && mish_continue(p->mish) && (*err == 0))
	{
		if (tfile->type == tf_ifile_rdonly)
			tfile->fd = open(tfile->path, O_RDONLY);
		else if (tfile->type == tf_ofile_creat)
			tfile->fd = open(tfile->path, O_RDWR | O_CREAT | O_TRUNC, 0644);
		else if (tfile->type == tf_ofile_append)
			tfile->fd = open(tfile->path, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (tfile->fd == -1)
			t_process_iofiles_error(p, errno, tfile->path, err);
		else if (!(tfile == t_process_iofile_get(p, 0) || \
		tfile == t_process_iofile_get(p, 1)))
			close_reset_fd(&(tfile->fd));
		tfile = tfile->next;
	}
}
*/