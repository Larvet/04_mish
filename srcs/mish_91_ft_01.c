/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_91_ft_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:29:31 by bchene            #+#    #+#             */
/*   Updated: 2024/05/24 11:56:06 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	is_alphanum_underscore(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	else
		return (0);
}

size_t	ft_strlen_while(char *str, int f(char))
{
	size_t	i;

	i = 0;
	while (str && str[i] && f(str[i]))
		i++;
	return (i);
}

/* retourne index + 1 ou 0 si n existe pas*/
int	ft_ischarinstr(char *str, char c)
{
	int	i;

	if(str == NULL)
		return (0);
	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

// equivaux a ft_freesplit ?
void	strtab_free(char **strtab)
{
	int	i;

	i = 0;
	if (strtab)
	{
		while (strtab[i])
		{
			free(strtab[i]);
			i++;
		}
		free(strtab);
	}
	return ;
}
