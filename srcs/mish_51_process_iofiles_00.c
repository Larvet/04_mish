/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_51_process_iofiles_00.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 15:52:59 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_process_iofile_free(t_process *process)
{
	if (process->iofiles)
		t_file_free(&(process->iofiles));
	process->iofiles = NULL;
	process->infile = NULL;
	process->outfile = NULL;
}

t_file	*t_process_iofile_add(t_process *p, char *path, t_tfile_type type)
{
	t_file	*new;
	t_file	*current;

	new = t_file_new(p->mish, path, type);
	if (p->iofiles == NULL)
		p->iofiles = new;
	else
	{
		current = p->iofiles;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (new);
}

void	t_process_inoutfile_get(t_process *process)
{
	t_file	*tf;

	tf = process->iofiles;
	while (tf)
	{
		if (tf->type == tf_ifile_rdonly || tf->type == tf_ifile_heredoc)
			process->infile = tf;
		else if (tf->type == tf_ofile_creat || tf->type == tf_ofile_append)
			process->outfile = tf;
		tf = tf->next;
	}
	if (process->infile == NULL)
		process->infile = \
		t_process_iofile_add(process, "stdin", tf_ifile_rdonly);
	if (process->outfile == NULL)
		process->outfile = \
		t_process_iofile_add(process, "stdout", tf_ofile_creat);	
}

void	t_process_iofile_close_unused_fds(t_process *process)
{
	t_file	*tf;

	tf = process->iofiles;
	while(tf)
	{
		if (tf != process->infile && tf != process->outfile)
			close_reset_fd(&(tf->fd));
		tf = tf->next;
	}
}

void	t_process_iofile_print(t_process *process)
{
	t_file	*tf;
	char	**ttype;

	ttype = ft_split("NONE HEREDOC RDONLY CREAT APPEND", ' ');
	if (ttype == NULL)
		return ;
	tf = process->iofiles;
	// printf("iofiles = ");
	// if (tf == NULL)
	// 	printf("(null)");
	// else
	// {
	// 	while (tf)
	// 	{
	// 		printf("(\"%s\", %s, %i) ", tf->path, ttype[tf->type], tf->fd);
	// 		tf = tf->next;
	// 	}
	// }
	printf("p%i : ", process->index);
	tf = process->infile;
	if(tf)
		printf("infile(\"%s\", %s, %i) ", tf->path, ttype[tf->type], tf->fd);
	tf = process->outfile;
	if(tf)
		printf("/ outfile(\"%s\", %s, %i) ", tf->path, ttype[tf->type], tf->fd);
	printf("\n");
	ft_freesplit(ttype);
}

/* inorout : ==0 IN - ==1 OUT */
/*
t_file	*t_process_iofile_get(t_process *process, int inorout)
{
	t_file	*tf;
	t_file	*ret;

	tf = process->iofiles;
	ret = NULL;
	while (tf)
	{
		if (inorout == 0 && (tf->type == tf_ifile_rdonly || tf->type == tf_ifile_heredoc))
			ret = tf;
		else if (inorout == 1 && (tf->type == tf_ofile_creat || tf->type == tf_ofile_append))
			ret = tf;
		tf = tf->next;
	}
	return (ret);
}
*/

/*
int	t_process_iofile_getfd(t_process *process, int inorout)
{
	int		ret;
	t_file	*tf;

	tf = t_process_iofile_get(process, inorout);
	if (tf == NULL)
		return (-1);
	ret = tf->fd;
	return (ret);
}
*/
