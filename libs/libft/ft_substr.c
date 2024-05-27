/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:31:14 by bchene            #+#    #+#             */
/*   Updated: 2023/11/07 14:35:05 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	getslen(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;

	slen = (unsigned int)ft_strlen(s);
	if (start >= slen)
		return (0);
	else if (slen - start < len)
		return (slen - start);
	return ((unsigned int)len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*buf;
	unsigned int	i;
	unsigned int	slen;

	if (s == NULL)
		return (NULL);
	slen = getslen(s, start, len);
	buf = malloc(sizeof(char) * slen + 1);
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
