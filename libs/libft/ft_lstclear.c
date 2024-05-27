/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:52 by bchene            #+#    #+#             */
/*   Updated: 2023/12/12 19:21:00 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lstcur;
	t_list	*lstnext;

	if (del && lst)
	{
		lstcur = *lst;
		while (lstcur)
		{
			lstnext = lstcur->next;
			ft_lstdelone(lstcur, del);
			lstcur = lstnext;
		}
		*lst = NULL;
	}
}
