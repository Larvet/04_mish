/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:30 by bchene            #+#    #+#             */
/*   Updated: 2023/10/30 15:27:35 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)(s + l));
	while (l--)
	{
		if (s[l] == (char)c)
			return ((char *)(s + l));
	}
	return (NULL);
}
