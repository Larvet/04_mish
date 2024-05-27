/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_01_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:26:04 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 15:43:34 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

// si erreur de malloc dans erreur comment sortir
t_err_type	mish_error_add(t_mish *mish, t_err_type t, int en, char *d)
{
	t_error	*new;

	new = t_error_new(t, en, d);
	if (new)
		t_error_add(&(mish->error), new);
	else
		return (err_malloc);
	return (t);
}

void	mish_error_treat(t_mish *mish)
{
	t_error	*error;

	error = mish->error;
	while (error)
	{
		if( err_malloc <= error->type && error->type <= err_fork)
			mish_error_print(error->err_no, error->data);
		else if( error->type == err_quote_open)
			write(2, "minishell: syntax error \' not closed\n", 37);
		else if( error->type == err_dquote_open)
			write(2, "minishell: syntax error \" not closed\n", 37);
		else if( error->type == err_token_unexpected)
		{
			write(2, "minishell: err_token_unexpected `", 34);
			write(2, error->data, ft_strlen(error->data));
			write(2, "\'\n", 3);
		}
		else if( error->type == err_unhandled)
		{
			write(2, "minishell: err_unhandled `", 27);
			write(2, error->data, ft_strlen(error->data));
			write(2, "\'\n", 3);
		}
		error = error->next;
	}
}

void	mish_error_treat_exit(t_mish *mish)
{
	t_error	*error;

	error = mish->error;
	while (error)
	{
		// if PID==parent...
		// if( error->type == err_exit && mish->nb == 1)
		if( error->type == err_exit)
			return;
		error = error->next;
	}
	t_error_lst_free(&(mish->error));
}

/*
void	mish_error_print(int en, char *str)
{
	write(2, "minishell: ", 11);
	if (str)
	{
		write(2, str, ft_strlen(str));
		if (ft_strlen(strerror(en)))
			write(2, " :", 2);
	}
	if (ft_strlen(strerror(en)))
		write(2, strerror(en), ft_strlen(strerror(en)));
	write(2, "\n", 1);
}
*/