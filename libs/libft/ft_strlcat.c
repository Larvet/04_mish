/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:24:54 by bchene            #+#    #+#             */
/*   Updated: 2023/11/07 10:58:44 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;

	if (size == 0)
		return ((size_t)ft_strlen(src));
	ldst = (size_t)ft_strlen(dst);
	if (size <= ldst)
		return (size + (size_t)ft_strlen(src));
	return (ldst + (size_t)ft_strlcpy(dst + ldst, src, size - ldst));
}
