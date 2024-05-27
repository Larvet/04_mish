/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:17:29 by bchene            #+#    #+#             */
/*   Updated: 2023/11/08 17:58:36 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnewfirst;
	t_list	*lstnew;
	t_list	*lstnewprev;

	lstnewfirst = NULL;
	while (lst && f && del)
	{
		lstnew = ft_lstnew(f(lst->content));
		if (lstnew == NULL)
		{
			ft_lstclear(&lstnewfirst, del);
			return (NULL);
		}
		if (lstnewfirst == NULL)
			lstnewfirst = lstnew;
		else
			lstnewprev->next = lstnew;
		lstnewprev = lstnew;
		lst = lst->next;
	}
	return (lstnewfirst);
}
