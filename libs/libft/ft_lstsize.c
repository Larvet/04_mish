/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:15:03 by bchene            #+#    #+#             */
/*   Updated: 2023/11/03 14:15:16 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*n;

	n = lst;
	if (n == NULL)
		return (0);
	size = -1;
	while (++size < 2147483647)
	{
		if (n->next == NULL)
			return (size + 1);
		n = n->next;
	}
	return (2147483647);
}
