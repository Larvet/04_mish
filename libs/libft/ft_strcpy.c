/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:30:55 by bchene            #+#    #+#             */
/*   Updated: 2024/05/17 13:34:56 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src && src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
