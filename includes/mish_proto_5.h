/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_proto_5.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:01 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 15:42:19 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTO_5_H
# define MISH_PROTO_5_H

/*						*/
/* 50_process			*/
void		t_process_free(t_process *process);
void		t_process_print(t_process *p);

/*						*/
/* 51_process_iofiles	*/
void		t_process_iofile_free(t_process *process);
t_file		*t_process_iofile_add(t_process *p, char *path, t_tfile_type t);
void		t_process_inoutfile_get(t_process *process);
void		t_process_iofile_close_unused_fds(t_process *process);
//t_file	*t_process_iofile_get(t_process *process, int inorout);
//int		t_process_iofile_getfd(t_process *process, int inorout);
void		t_process_iofile_print(t_process *process);

t_file		*t_process_line_to_file(t_process *p, char *line);
void		t_file_add_back_rec(t_file **lst, t_file *new);

/*					*/
/* 52_process_cmd	*/
void		t_process_cmd_free(t_process *process);
char		*t_process_cmd_get(t_process *process);
void        t_process_cmd_setempty(t_process *process);
int			t_process_cmd_isempty(t_process *process);
int			t_process_cmd_isbuiltin(t_process *process);

/*						*/
/* 53_process_exec		*/
t_err_type	mish_exec(t_mish *mish);
t_err_type	t_process_exec_builtin(t_process *process);
t_err_type	mish_fork_parent(t_mish *mish);
t_err_type	t_process_fork_child(t_process *p);

/*						*/
/* 54_process_pipe		*/
void		close_reset_fd(int *fd);
t_err_type	t_process_pipe_fds(t_process *process);
t_err_type	t_process_dup_io(t_process *p);
t_err_type	t_process_dup_io_builtin(t_process *p);

#endif
