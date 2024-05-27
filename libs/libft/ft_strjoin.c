/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:31:34 by bchene            #+#    #+#             */
/*   Updated: 2024/05/24 12:08:01 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	int		i;
	int		ls1;
	int		ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = (int)ft_strlen(s1);
	ls2 = (int)ft_strlen(s2);
	buf = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (buf == NULL)
		return (NULL);
	i = -1;
	while (++i < ls1)
		buf[i] = s1[i];
	i--;
	while (++i < (ls1 + ls2))
		buf[i] = s2[i - ls1];
	buf[i] = '\0';
	return (buf);
}

char	*ft_strjointo(char *s1, char const *s2)
{
	char	*buf;
	int		i;
	int		ls1;
	int		ls2;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		ls1 = 0;
	else
		ls1 = (int)ft_strlen(s1);
	ls2 = (int)ft_strlen(s2);
	buf = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (buf == NULL)
		return (NULL);
	i = -1;
	while (++i < ls1)
		buf[i] = s1[i];
	i--;
	while (++i < (ls1 + ls2))
		buf[i] = s2[i - ls1];
	buf[i] = '\0';
	if (s1)
		free(s1);
	return (buf);
}

char	*ft_strjointoleft(char *s1, char const *s2)
{
	char	*buf;
	int		i;
	int		ls1;
	int		ls2;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		ls1 = 0;
	else
		ls1 = (int)ft_strlen(s1);
	ls2 = (int)ft_strlen(s2);
	buf = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (buf == NULL)
		return (NULL);
	i = -1;
	while (++i < ls2)
		buf[i] = s2[i];
	i--;
	while (++i < (ls1 + ls2))
		buf[i] = s1[i - ls2];
	buf[i] = '\0';
	if (s1)
		free(s1);
	return (buf);
}

/* ft_strjoinva penser a mettre NULL a la fin */
char	*ft_strjoinva(char *str, ...)
{
	va_list	param;
	char	*dest;
	char	*bufstr;

	dest = NULL;
	if (str)
	{
		va_start(param, str);
		bufstr = str;
		while (bufstr)
		{
			dest = ft_strjointo(dest, bufstr);
			bufstr = va_arg(param, char *);
		}
		va_end(param);
		return (dest);
	}
	return (NULL);
}
