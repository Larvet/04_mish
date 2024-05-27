/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_60_t_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:23:22 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

// tf->line est peut etre inutile
t_file	*t_file_new(t_mish *mish, char *path, t_tfile_type type)
{
	t_file	*tf;

	tf = malloc(sizeof(t_file));
	if (tf == NULL)
	{
		mish_error_add(mish, err_malloc, errno, "t_file_new");
		return (NULL);
	}
	tf->fd = -1;
	tf->path = ft_strdup(path);
	tf->type = type;
	tf->next = NULL;
	tf->line = ft_strempty(NULL); // a enlever ?
	return (tf);
}

void	t_file_free(t_file **tf)
{
	if (*tf)
	{
		if ((*tf)->next)
			t_file_free(&((*tf)->next));
		t_file_del(tf);
	}
}

void	t_file_del(t_file	**tf)
{
	if (*tf)
	{
		if ((*tf)->path)
			free((*tf)->path);
		if ((*tf)->line)
			free((*tf)->line);
		free(*tf);
		*tf = NULL; //a tester
	}
}

int t_process_iofiles_error(t_process *p, int en, char *path)
{
	builtin_perror(p, en, path, 1);
	// mish_error_print(en, path);	
	if (p)
		t_process_cmd_setempty(p);
	p->infile = t_process_iofile_add(p, "error", tf_ifile_rdonly);
	p->outfile = t_process_iofile_add(p, "error", tf_ofile_creat);
	// t_process_iofile_add(p, "error", tf_ifile_rdonly);
	// t_process_iofile_add(p, "error", tf_ofile_creat);
	return (p->exitstatus); // a test
}

void	mish_error_print(int en, char *str)
{
	write(2, "minishell: ", 11);
	if (str)
	{
		write(2, str, ft_strlen(str));
		if (ft_strlen(strerror(en)))
			write(2, " :", 2);
	}
	if (ft_strlen(strerror(en)))
		write(2, strerror(en), ft_strlen(strerror(en)));
	write(2, "\n", 1);
}