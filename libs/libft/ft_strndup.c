/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:09:11 by bchene            #+#    #+#             */
/*   Updated: 2024/05/17 13:36:10 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int size)
{
	char	*dup;
	int		i;

	if (src == NULL)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdupfree(char *dest, const char *src)
{
	if (dest)
	{
		free(dest);
		dest =NULL;
	}
	dest = ft_strdup(src);
	return (dest);
}
