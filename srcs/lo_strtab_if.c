/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strtab_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:30:34 by locharve          #+#    #+#             */
/*   Updated: 2024/05/14 17:42:10 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	strtab_count_if(char **src, t_tfile_type f(char *), int b)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (src[i])
	{
		if ((b && f(src[i])) || (!b && !f(src[i])))
			count++;
		i++;
	}
	return (count);
}

static char	**strtab_set_if(char **dst, char **src, t_tfile_type f(char *), int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if ((b && f(src[i])) || (!b && !f(src[i])))
		{
			dst[j] = src[i];
			j++;
		}
		i++;
	}
	return (dst);
}

char **strtab_dup_if(char **src, t_tfile_type f(char *), int b)
{
	char	**dst;
	int		count;

	count = strtab_count_if(src, f, b);
	dst = ft_calloc(count + 1, sizeof(char *));
	if (dst && count) 					// ca fait la diff ?
		dst = strtab_set_if(dst, src, f, b);
	return (dst);
}
