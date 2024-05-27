/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:28:42 by bchene            #+#    #+#             */
/*   Updated: 2023/11/06 16:50:46 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (!(*p1 - *p2) && n - 1)
	{
		p1++;
		p2++;
		n--;
	}
	if (n)
		return ((int)(*p1 - *p2));
	return (0);
}
