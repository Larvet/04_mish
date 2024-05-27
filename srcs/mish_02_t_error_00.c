/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_02_t_error_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:03 by bchene            #+#    #+#             */
/*   Updated: 2024/05/14 16:22:32 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_error	*t_error_new(t_err_type t, int en, char *d)
{
	t_error	*new;

	new = malloc(sizeof(t_error));
	if (new)
	{
		new->type = t;
		new->err_no = en;
		new->data = ft_strdup(d);
		new->next = NULL;
	}
	return (new);
}

void	t_error_add(t_error **lst, t_error *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			t_error_add(&(*lst)->next, new);
	}
	return ;
}

void	t_error_del(t_error **err)
{
	if ((*err))
	{
		if ((*err)->data)
		{
			free((*err)->data);
			(*err)->data = NULL;
		}
		free((*err));
		*err = NULL;
	}
}

void	t_error_lst_free(t_error **err)
{
	if (err)
	{
		if (*err)
		{
			if ((*err)->next)
				t_error_lst_free(&(*err)->next);
			t_error_del(err);
		}
	}
}

t_err_type	t_error_exist(t_error *err)
{
	if (err)
		if (err->type)
			return (err->type);
	return (err_none);
}
