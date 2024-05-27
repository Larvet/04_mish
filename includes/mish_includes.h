/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_includes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:08:57 by bchene            #+#    #+#             */
/*   Updated: 2024/05/14 10:47:28 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_INCLUDES_H
# define MISH_INCLUDES_H

/* Pour readline, rl_clear_history, rl_on_new_line, rl_replace_line, */
/* rl_redisplay, add_history */
# include <readline/readline.h>
# include <readline/history.h>
/* Pour printf, perror */
# include <stdio.h>
/* Pour malloc, free, exit */
# include <stdlib.h>
/* Pour write, access, open, read, close, fork, wait, waitpid, wait3, */
/* wait4, isatty, ttyname, ttyslot, ioctl */
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
/* Pour signal, sigaction, sigemptyset, sigaddset, kill */
# include <signal.h>
/* Pour getcwd, chdir, stat, lstat, fstat, unlink, execve */
# include <sys/stat.h>
/* Pour dup, dup2, pipe */
# include <unistd.h>
/* Pour opendir, readdir, closedir */
# include <dirent.h>
/* Pour strerror, errno */
# include <string.h>
# include <errno.h>
/* Pour getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, */
/* tgetstr, tgoto, tputs */
# include <term.h>
# include <termios.h>
# include <curses.h>
/* Pour gettimeofday */
# include <sys/time.h>
/* Pour getrusage */
# include <sys/resource.h>
/* libft ft_printf GNL */
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

#endif
