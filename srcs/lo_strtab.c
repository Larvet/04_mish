/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:46 by locharve          #+#    #+#             */
/*   Updated: 2024/05/23 13:45:00 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

char	**strtab_addstr(char **strtab, char *str)
{
	char				**dst;
	unsigned int		i;

	if (!strtab)
		return (NULL);
	dst = ft_calloc(ft_splitsize(strtab) + 2, sizeof(char *));
	if (dst)
	{
		i = 0;
		while (strtab[i])
		{
			dst[i] = strtab[i];
			i++;
		}
		dst[i] = str;
		dst[i + 1] = NULL;
	}
	return (dst);
}

void	strtab_print(char **strtab, char *sep)
{
	unsigned int	i;
	size_t			len_sep;

	len_sep = ft_strlen(sep);
	i = 0;
	while (strtab && strtab[i])
	{
		write(1, strtab[i], ft_strlen(strtab[i]));
		if (strtab[i + 1] && strtab[i + 2])
			write(1, sep, len_sep);
		i++;
	}
	return ;
}