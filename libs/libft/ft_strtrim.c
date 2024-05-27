/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:35:05 by bchene            #+#    #+#             */
/*   Updated: 2023/11/07 14:38:32 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_trim_start(char const *s1, char const *set)
{
	int	i;
	int	lset;

	lset = ft_strlen(set);
	if (!s1[0] || !lset)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, (int)s1[i]))
			return (i);
		i++;
	}
	return (i);
}

static unsigned int	get_trim_end(char const *s1, char const *set)
{
	int	i;
	int	lset;

	lset = ft_strlen(set);
	i = ft_strlen(s1);
	if (lset == 0)
		return ((unsigned int)i);
	if (!s1[0] || !lset)
		return (0);
	i--;
	while (s1[i])
	{
		if (!ft_strrchr(set, (int)s1[i]))
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s;
	unsigned int	e;

	if (!s1 || !set)
		return (NULL);
	s = get_trim_start(s1, set);
	e = get_trim_end(s1, set);
	return (ft_substr(s1, s, (size_t)(e - s + 1)));
}
