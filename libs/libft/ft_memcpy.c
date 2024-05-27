/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:23:23 by bchene            #+#    #+#             */
/*   Updated: 2023/11/06 14:36:12 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;

	if (!src && !dest)
		return (dest);
	ucdest = (void *) dest;
	ucsrc = (void *) src;
	while (n)
	{
		*ucdest = (unsigned char) *ucsrc;
		ucsrc++;
		ucdest++;
		n--;
	}
	return (dest);
}
