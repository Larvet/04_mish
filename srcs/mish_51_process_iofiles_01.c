/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_51_process_iofiles_01.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 15:54:06 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_file	*t_process_line_to_file(t_process *p, char *line)
{
	t_file			*file;
	char			*path;
	t_tfile_type	file_type;

	path = t_file_line_get_path(line);
	file_type = t_file_line_get_type(line);
	file = t_file_new(p->mish, path, file_type);
	//file = t_process_iofile_add(p, path, file_type);
	return (file);
}

void	t_file_add_back_rec(t_file **lst, t_file *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			t_file_add_back_rec(&(*lst)->next, new);
	}
}
