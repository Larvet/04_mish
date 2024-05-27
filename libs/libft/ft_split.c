/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:38:24 by bchene            #+#    #+#             */
/*   Updated: 2024/05/13 16:35:59 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitsize(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

void	*ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	if (split)
		free(split);
	return (NULL);
}

static char	**splitit(char *s, char c, char **split, int nb)
{
	int	i;
	int	etat;
	int	j;
	int	count;

	i = 0;
	etat = 0;
	count = 0;
	while (count < nb)
	{
		if (!etat && (int)s[i] != c)
		{
			j = i;
			etat = 1;
		}
		else if ((etat && (int)s[i] == c) || !s[i])
		{
			split[count] = ft_strndup(s + j, i - j);
			if (split[count++] == NULL)
				return (ft_freesplit(split));
			etat = 0;
		}
		i++;
	}
	return (split);
}

int	ft_getnbsplit(char *s, char c)
{
	int	i;
	int	etat;
	int	nb;

	i = 0;
	etat = 0;
	nb = 0;
	while (s[i])
	{
		if (!etat && (int)s[i] != c)
		{
			nb++;
			etat = 1;
		}
		else if (etat && (int)s[i] == c)
			etat = 0;
		i++;
	}
	return (nb);
}

char	**ft_split(char const *src, char c)
{
	char	*s;
	char	**split;
	int		nb;

	if (!src)
		return (NULL);
	s = (char *)src;
	if (s[0] == '\0')
		nb = 0;
	else if (c == '\0')
		nb = 1;
	else
		nb = ft_getnbsplit(s, c);
	split = malloc((nb + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	if (nb)
		if (splitit(s, c, split, nb) == NULL)
			return (NULL);
	split[nb] = NULL;
	return (split);
}
