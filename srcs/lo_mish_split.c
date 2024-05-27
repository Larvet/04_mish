/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_mish_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:54:51 by locharve          #+#    #+#             */
/*   Updated: 2024/05/13 16:12:46 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	m_count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{		
		if (i > 0 && str[i] == c && str[i - 1] != c
				&& !is_between_quotes(str, i))
			count++;
		i++;
	}
	if (i > 0 && str[i - 1] != c)
		count++;
	return (count);
}

static char	*str_piece_cpy(char *s, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc((end - start + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (start < end)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*from_str_to_strs(char *s, int *i, char c)
{
	char	*dst;
	int		j;

	while (s[*i] == c)
		*i += 1;
	j = *i;
	while (s[j])
	{
		if (s[j] == c && !is_between_quotes(s, j))
			break ;
		j++;
	}
	dst = str_piece_cpy(s, *i, j);
	*i = j;
	return (dst);
}

static void	free_all(char **split, int nbr_str)
{
	int	i;

	i = 0;
	while (i < nbr_str)
	{
		if (split[i] != NULL)
			free(split[i]);
		i++;
	}
	if (split != NULL)
		free(split);
}

char	**mish_split(char *s, char c)
{
	char	**split;
	int		nbr_str;
	int		i;
	int		index;

	if (s == NULL)
		return (NULL);
	nbr_str = m_count_words(s, c);
	split = (char **)malloc((nbr_str + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (i < nbr_str)
	{
		split[i] = from_str_to_strs(s, &index, c);
		if (!split[i])
		{
			free_all(split, nbr_str);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
