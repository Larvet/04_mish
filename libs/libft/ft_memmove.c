/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:23:44 by bchene            #+#    #+#             */
/*   Updated: 2023/11/06 14:37:18 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ucsrc;
	unsigned char	*ucdest;

	ucsrc = (unsigned char *)src;
	ucdest = (unsigned char *)dest;
	if (!src && !dest)
		return ((void *)dest);
	if (src < dest)
	{
		i = 0;
		while (++i <= n)
			ucdest[n - i] = ucsrc[n - i];
	}
	else
	{
		i = -1;
		while (++i < n)
			ucdest[i] = ucsrc[i];
	}
	return ((void *)dest);
}
