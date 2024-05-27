/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_t_process_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:28:20 by locharve          #+#    #+#             */
/*   Updated: 2024/05/13 18:27:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	count_words(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		while (str[i] && is_in_str(sep, str[i]))
			i++;
		if (str[i] && !is_in_str(sep, str[i]))
		{
			i += handle_word(str, sep, i);
			count++;
		}
	}
	return (count);
}

static char	*substr_dup(char *str, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = ft_calloc((end - start + 1), sizeof(char));
	if (tmp)
	{
		i = 0;
		while (start + i < end)
		{
			tmp[i] = str[start + i];
			i++;
		}
	}
	return (tmp);
}

// gerer les quotes, caracteres speciaux entre quotes
static char	*from_str_to_strs(char *str, int *i, char *sep)
{
	char	*dst;
	int		j;
	int		tmp;

	while (str[*i] && is_in_str(sep, str[*i]))
		*i += 1;
	j = *i;
	if (str[j] && !is_in_str(sep, str[j]))
	{
		tmp = handle_word(str, sep, j);
		if (tmp < 0)
			return (NULL);
		else
			j += tmp;
	}
	dst = substr_dup(str, *i, j);
	*i = j;
	return (dst);
}

char	**t_process_split(t_process *p, char *sep)
{
	char	**dst;
	int		count;
	int		i;
	int		index;

	if (!p->line)
		return (NULL);
	count = count_words(p->line, sep);
	dst = ft_calloc(count + 1, sizeof(char *));
	if (dst)
	{
		i = 0;
		index = 0;
		while (i < count)
		{
			dst[i] = from_str_to_strs(p->line, &index, sep);
			if (!dst[i])
			{
				strtab_free(dst);
				return (NULL);
			}
			i++;
		}
	}
	return (dst);
}
