/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_proto_7.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:11:01 by bchene            #+#    #+#             */
/*   Updated: 2024/05/24 09:56:18 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTO_7_H
# define MISH_PROTO_7_H

/*						*/
/* 70_builtin			*/
void    t_process_builtin(t_process *process);
void    builtin_free(t_process *process);
void	builtin_error(t_process *p,char *str, int exitstatus);
void	builtin_perror(t_process *p,int err ,char *str, int exitstatus);
int		t_process_is_invalid_option(t_process *p);

/*						*/
/* 71_echo				*/
void	builtin_echo(t_process *process);

/*						*/
/* 72_cd                */
void	mish_cd(t_process *p);
void	builtin_cd(t_process *process);

/*						*/
/* 73_pwd				*/
void	builtin_pwd(t_process *process);

/*						*/
/* 74_export			*/
void	builtin_export(t_process *process);

/*						*/
/* 75_unset			*/
void	builtin_unset(t_process *process);

/*						*/
/* 76_env			*/
void	builtin_env(t_process *process);

/*						*/
/* 77_exit				*/
void	builtin_exit(t_process *process);

/*						*/
/* 78_nocmd_pmish		*/
void	builtin_no_cmd(t_process *process);
void	builtin_no_access_cmd(t_process *process);

/*						*/
/* 79_pmish_pes			*/
void	builtin_pmish(t_process *process);
void	builtin_pes(t_process *process);

#endif
