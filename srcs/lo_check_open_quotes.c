/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_check_open_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:54:49 by locharve          #+#    #+#             */
/*   Updated: 2024/05/20 18:59:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	mish_check_open_quotes(t_mish *mish)
{
	int		i;
	char	q;

	i = 0;
	q = 0;
	while (mish->line && mish->line[i])
	{
		if (mish->line[i] == '\'' || mish->line[i] == '\"')
		{
			q = mish->line[i];
			i++;
			while (mish->line[i] && mish->line[i] != q)
				i++;
			if (!mish->line[i])
			{
				if (q == '\'')
					return (mish_error_add(mish, err_quote_open, errno, NULL));
					//return (dup_err_str(mish, "", 0, err_quote_open));
				else if (q == '\"')
					return (mish_error_add(mish, err_dquote_open, errno, NULL));
					//return (dup_err_str(mish, "", 0, err_dquote_open));
			}
		}
		i++;
	}
	return (0);
}
