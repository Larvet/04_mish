/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_handle_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:12:38 by locharve          #+#    #+#             */
/*   Updated: 2024/05/22 16:27:21 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

// gerer "salut"poto"ca va ?" -> [salutpotoca va ?]

int	handle_quotes(char *str, int i, char q)
{
	int	j;

	j = 1;
	while (str[i + j] && str[i + j] != q)
		j++;
	j++;
	while (str[i + j] && ((!is_in_str(WHITESPACES, str[i + j])
			&& !is_in_str(SPECIAL_SEP, str[i + j]))
			|| is_between_quotes(str, i + j)))
		j++;
	return (j);
}

int	handle_redirections(char *str, int i, char r)
{
	int	j;

	j = 1;
	if (str[i + j] == r)
		j++;
	while (is_in_str(WHITESPACES, str[i + j]))
		j++;
	while (str[i + j] && !is_in_str(WHITESPACES, str[i + j])
			&& !is_in_str(SPECIAL_SEP, str[i + j]))
		j++;
	return (j);
}

int	handle_specials(char *str, int i)
{
	char	c;

	c = str[i];
	if (is_in_str("\'\"", c))
		return (handle_quotes(str, i, c));
	else if (is_in_str("<>", c))
		return (handle_redirections(str, i, c));
	else if (c == '|')
		return (1);
	else
		return (-1);
}

int	handle_word(char *str, char *sep, int i)
{
	int	j;

	j = 0;
	if (is_in_str(SPECIAL_SEP, str[i]) || is_in_str("\'\"", str[i]))
		j = handle_specials(str, i);
	while (str[i + j] && !is_in_str(sep, str[i + j]) // else (avant)
			&& !is_in_str(SPECIAL_SEP, str[i + j]))
	{
		if (is_in_str("\'\"", str[i + j]))
			j += handle_quotes(str, i + j, str[i + j]); //////
		else
			j++;
	}
	return (j);
}
