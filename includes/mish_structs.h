/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:12:03 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 17:18:34 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_STRUCTS_H
# define MISH_STRUCTS_H

typedef struct s_mish		t_mish;
typedef struct s_process	t_process;
typedef struct s_file		t_file;
typedef struct s_error		t_error;
typedef struct s_env		t_env;
typedef struct sigaction	t_sa;

/*
env -i bash
recuperer les varialble envirenement au denbut et emuler les unset et set
*/

typedef struct s_mish
{
	t_error		*error;
	char		*prompt;
	char		*line;
	char		**splitline;
	int			nb;
	t_process	*p;
	int			**fds;
	int			*pid;
	t_env		*env;
	t_env		*unset;
	char		**pathlist;
	t_sa		sa;
}	t_mish;

typedef struct s_process
{
	t_mish		*mish;
	int			index;
	char		*line;
	int			ac;
	char		**av;
	char		*cmd;
	t_file		*iofiles;
	t_file		*infile;
	t_file		*outfile;
	int			fdinbkp;
	int			fdoutbkp;
	int			exitstatus;
}	t_process;

typedef struct s_file
{
	int				fd;
	char			*line;
	char			*path;
	t_tfile_type	type;
	t_file			*next;
}	t_file;

typedef struct s_error
{
	t_err_type	type;
	int			err_no;
	char		*data;
	t_error		*next;
}	t_error;

typedef struct s_env
{
	char	*var;
	char	*data;
	t_env	*next;
}	t_env;

#endif
