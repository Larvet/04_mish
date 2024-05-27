/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_enums.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:10:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/22 18:01:58 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_ENUMS_H
# define MISH_ENUMS_H

typedef enum e_err_type
{
	err_none,
	err_malloc,
	err_dup,
	err_dup2,
	err_pipe,
	err_fork,
	err_execve,
	err_quote_open,
	err_dquote_open,
	err_unhandled,
	err_token_unexpected,
	err_exit
}	t_err_type;

typedef enum e_tfile_type
{
	tf_none,
	tf_ifile_heredoc,
	tf_ifile_rdonly,
	tf_ofile_creat,
	tf_ofile_append
}	t_tfile_type;

#endif
