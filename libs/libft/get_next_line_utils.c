/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:01:35 by bchene            #+#    #+#             */
/*   Updated: 2023/12/06 16:53:36 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_lstcatbuf(t_gnlist *node, char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (node)
	{
		len = node->len;
		if (node->nl)
			len = node->nl;
		j = 0;
		while (j < len)
		{
			str[i] = node->buffer[j];
			i++;
			j++;
		}
		node = node->next;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_getlstline(t_gnlist *lst)
{
	t_gnlist	*node;
	char		*str;
	int			len;

	node = lst;
	len = 0;
	while (node)
	{
		if (node->nl)
			len += node->nl;
		else
			len += node->len;
		node = node->next;
	}
	len++;
	if (len == 1)
		return (NULL);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str = gnl_lstcatbuf(lst, str);
	return (str);
}

int	gnl_lstadd_back(t_gnlist **lst, t_gnlist *node)
{
	t_gnlist	*cur;

	if (node == NULL)
		return (-1);
	cur = *lst;
	if (cur == NULL)
	{
		*lst = node;
		return (node->len - node->nl);
	}
	else
	{
		while (cur)
		{
			if (cur->next == NULL)
			{
				cur->next = node;
				return (node->len - node->nl);
			}
			cur = cur->next;
		}
	}
	return (-1);
}

t_gnlist	*gnl_lstnew(char *buffer)
{
	t_gnlist	*new;
	int			i;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	new = malloc(sizeof(t_gnlist));
	if (new == NULL)
		return (NULL);
	i = 0;
	new->nl = 0;
	while (buffer[i])
	{
		new->buffer[i] = buffer[i];
		if (buffer[i] == '\n' && new->nl == 0)
			new->nl = i + 1;
		i++;
	}
	new->len = i;
	new->buffer[i] = '\0';
	new->next = NULL;
	return (new);
}

void	gnl_lstclear(t_gnlist **lst)
{
	t_gnlist	*lstcur;
	t_gnlist	*lstnext;

	if (lst)
	{
		lstcur = *lst;
		while (lstcur)
		{
			lstnext = lstcur->next;
			free(lstcur);
			lstcur = lstnext;
		}
		*lst = NULL;
	}
}
