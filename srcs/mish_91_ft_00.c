/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_91_ft_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:29:31 by bchene            #+#    #+#             */
/*   Updated: 2024/05/14 12:12:07 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	ft_strfree(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

char	*ft_strnrchr(char *str, int n, char c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0 && n > 0)
	{
		i--;
		if (str[i] == c)
			n--;
	}
	return (&str[i]);
}

/* free str and return empty char* "" */
char	*ft_strempty(char *str)
{
	if (str)
		free(str);
	str = malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = 0;
	return (str);
}

/* printf split parts */
void	ft_print_split(char **pathlist)
{
	int	j;

	if (pathlist)
	{
		j = -1;
		while (pathlist[++j])
			ft_printf("%s\n", pathlist[j]);
	}
	else
	{
		ft_printf("(null)\n");
	}
}

void	ft_printf_strtab(char **str, int size, const char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != 0)
			printf("%s", sep);
		if (str[i])
			printf("%s", str[i]);
		i++;
	}
}
