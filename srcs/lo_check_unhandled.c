/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_check_unhandled.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:54:20 by locharve          #+#    #+#             */
/*   Updated: 2024/05/15 18:13:35 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	is_between_quotes(char *str, int i)
{
	int		j;
	int		q;

	j = 0;
	q = -1;
	while (str && str[j] && j < i)
	{
		if (q < 0 && (str[j] == '\'' || str[j] == '\"'))
			q = j;
		else if (q >= 0 && str[j] == str[q])
			q = -1;;
		j++;
	}
	if (q >= 0)
	{
		j++;
		while (str && str[j] && str[j] != str[q])
			j++;
		if (str[j] && str[q] == '\'')
			return (1);
		else if (str[j] && str[q] == '\"')
			return (2);
	}
	return (0);
}

int	mish_check_unhandled(t_mish *mish)
{
	char	*err;
	int		i;

	i = 0;
	while (mish->line && mish->line[i])
	{
		if (is_in_str("\\;&()", mish->line[i])
				&& !is_between_quotes(mish->line, i))
		{
			err = ft_calloc(2, sizeof(char));
			if (err)
			{
				err[0] = mish->line[i];
				mish_error_add(mish, err_unhandled, errno, err);
				free(err);
				return (err_unhandled);
			}
			else
				return (mish_error_add(mish, err_malloc, errno,
						"check_unhandled"));
		}
		i++;
	}
	return (0);
}