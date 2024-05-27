/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_mish_check_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:35:00 by locharve          #+#    #+#             */
/*   Updated: 2024/05/15 18:16:22 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_first_substitution(t_mish *mish)
{
	int	v;

	v = is_there_a_var(mish->line);
	while (v >= 0)
	{
		if (is_between_quotes(mish->line, v) != 1)
			mish_var_dup(mish, &mish->line, &mish->line[v]);
		v = is_there_a_var(mish->line);
	}
	return (t_error_exist(mish->error));
}

t_err_type  mish_check_line(t_mish *mish)
{
	if (mish && mish->line && (!mish->line[0] ///
			|| (!mish_check_syntax_error(mish)
			&& !mish_check_unhandled(mish)
			&& !mish_check_open_quotes(mish))))
		return (0);
	else
		return (t_error_exist(mish->error));
}