/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:09:30 by locharve          #+#    #+#             */
/*   Updated: 2024/05/22 16:19:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	init_range(char *str, int *start, int *end)
{
	if (*end && str)
	{
		if (*end >= 1)
			*start = *end - 1;
		else if (*end > *start)
			*start = 0;
		else
			return (0);
	}
	while (str[*start] && !is_in_str("\'\"", str[*start]))
		*start += 1;
	*end = *start + 1;
	while (str[*start] && str[*end] && str[*end] != str[*start])
		*end += 1;
	if (str[*start] && str[*end] && *end <= (int)ft_strlen(str))
		return (1);
	else
		return (0);
}

static char	*copy_removing(char *dst, char *src, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src && src[i + j])
	{
		if (i + j == start)
			j++;
		if (i + j == end)
			j++;
		dst[i] = src[i + j];
		if (src[i + j])
			i++;
	}
	return (dst);
}

// add + 1
t_err_type  mish_remove_quotes(t_mish *mish, char **p_lines)
{
    char    *new_line;
    int     start;
	int		end;
    int     i;

    i = 0;
    while (p_lines && p_lines[i])
    {
		start = 0;
		end = 0;
        while (init_range(p_lines[i], &start, &end))
        {
            new_line = ft_calloc(ft_strlen(p_lines[i]) - 2 + 1, sizeof(char));
			if (new_line)
				new_line = copy_removing(new_line, p_lines[i], start, end);
			else
				mish_error_add(mish, err_malloc, errno, "mish_remove_quotes");
			free(p_lines[i]);
			p_lines[i] = new_line;
        }
        i++;
    }
	return (t_error_exist(mish->error));
}
