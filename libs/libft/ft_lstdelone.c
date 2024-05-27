/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:20 by bchene            #+#    #+#             */
/*   Updated: 2023/12/12 17:57:49 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		if (lst->content)
			del(lst->content);
		free(lst);
	}
}
