/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:49 by bchene            #+#    #+#             */
/*   Updated: 2024/04/24 15:57:23 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if ((char)c == 0)
		return (p);
	return (NULL);
}

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (!str[i])
		return (0);
	else
		return (i + 1);
}

char	*ft_strswitnchr(char *s, char src, char dest)
{
	char	*s1;

	s1 = ft_strchr(s, src);
	if (s1)
		*s1 = dest;
	return (s);
}
