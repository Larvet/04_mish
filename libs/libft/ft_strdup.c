/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:30:55 by bchene            #+#    #+#             */
/*   Updated: 2024/04/24 15:21:36 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*dup;

	l = ft_strlen(s);
	dup = malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, l);
	dup[l] = '\0';
	return (dup);
}
