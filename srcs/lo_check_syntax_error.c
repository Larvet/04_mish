/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_check_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:54:13 by locharve          #+#    #+#             */
/*   Updated: 2024/05/20 19:10:46 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static size_t	token_len(char *str)
{
	if (str && *str)
	{
		if (is_in_str("<>", *str))
		{
			if (*str == *(str + 1))
				return (2);
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

static char	*token_dup(char *str)
{
	char	*dst;
	size_t	len;

	dst = NULL;
	if (str)
	{
		len = token_len(str);
		dst = strndup(str, len);
	}
	return (dst);
}

static void	mish_set_unexpected_error(t_mish *mish, char *curr_t, char *next_t)
{
	if (!ft_strcmp(curr_t, "|"))
	{
		if (!ft_strcmp(next_t, "|"))
			mish_error_add(mish, err_token_unexpected, errno, next_t);
		else if (!*next_t)
			mish_error_add(mish, err_token_unexpected, errno, "newline");
	}
	else if (is_in_str("<>", *curr_t))
		mish_error_add(mish, err_token_unexpected, errno, next_t);
	return ;
}

static int	mish_check_unexpected(t_mish *mish, char *str, char *curr_t)
{
	char	*next_t;

	if (mish && str && curr_t)
	{
		next_t = token_dup(&str[ft_strlen(curr_t) +
				ft_strlen_while(&str[ft_strlen(curr_t)], ft_isspace)]);
		if (next_t)
		{
			if (!*next_t || is_in_str("|<>", *next_t))
				mish_set_unexpected_error(mish, curr_t, next_t);
			free(next_t);
		}
	}
	return (t_error_exist(mish->error));
}

int	mish_check_syntax_error(t_mish *mish)
{
	char	*curr_t;
	int		i;

	i = 0;
	while (mish && mish->line && mish->line[i])
	{
		if (is_in_str("|<>", mish->line[i])
				&& !is_between_quotes(mish->line, i)
				&& !t_error_exist(mish->error))
		{
			curr_t = token_dup(&mish->line[i]);
			if (curr_t)
			{
				mish_check_unexpected(mish, &mish->line[i], curr_t); //
				i += ft_strlen(curr_t);
				free(curr_t);
			}
			else
				return (mish_error_add(mish, err_malloc,
						errno, "mish_check_syntax_error"));
		}
		else
			i++;
	}
	return (t_error_exist(mish->error));
}
