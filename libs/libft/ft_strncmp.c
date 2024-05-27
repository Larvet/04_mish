/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:52 by bchene            #+#    #+#             */
/*   Updated: 2024/05/16 18:46:07 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = s1[i];
		c2 = s2[i];
		if ((c1 - c2) || !(c1 && c2))
			return ((int)(c1 - c2));
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
	{
		if(s1 == s2)
			return (0);
		return (42);
	}
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	return (s1[i] - s2[i]);
}
