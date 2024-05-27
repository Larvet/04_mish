/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:04 by bchene            #+#    #+#             */
/*   Updated: 2023/11/07 15:08:30 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*buf;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	buf = malloc(sizeof(char) * (size + 1));
	if (buf == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		buf[i] = f(i, s[i]);
	buf[i] = '\0';
	return (buf);
}
