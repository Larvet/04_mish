/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_70_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:36:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:12:13 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_process_builtin(t_process *process)
{
	if ((process->av)[0] == NULL) 
		builtin_no_cmd(process);
	if (!ft_strcmp((process->av)[0], "echo")) 
		builtin_echo(process);
	else if (!ft_strcmp((process->av)[0], "cd"))
		builtin_cd(process);
	else if (!ft_strcmp((process->av)[0], "pwd"))
		builtin_pwd(process);
	else if (!ft_strcmp((process->av)[0], "export"))
		builtin_export(process);
	else if (!ft_strcmp((process->av)[0], "unset"))
		builtin_unset(process);
	else if (!ft_strcmp((process->av)[0], "env"))
		builtin_env(process);
	else if (!ft_strcmp((process->av)[0], "exit"))
		builtin_exit(process);
	else if (!ft_strcmp((process->av)[0], "pmish"))
		builtin_pmish(process);
	else if (!ft_strcmp((process->av)[0], "pes"))
		builtin_pes(process);
	else
		builtin_no_access_cmd(process);
	builtin_free(process);
}

void	builtin_free(t_process *process)
{
	int exstat;

	if (process->mish->nb > 1)
	{
		mish_error_treat(process->mish);
		t_error_lst_free(&(process->mish->error));
		exstat = mish_exit_status_get(process->mish);
		mish_free(process->mish, 0);
		exit (exstat);
	}
}

void	builtin_error(t_process *p,char *str, int exitstatus)
{
	if (str)
		write(2, str, ft_strlen(str));
	mish_exit_status_set(p->mish, exitstatus);
	// if (p->exitstatus)
	// 	return;
	// if (str)
	// 	write(2, str, ft_strlen(str));
	// p->exitstatus = exitstatus;
}

void	builtin_perror(t_process *p,int err ,char *str, int exitstatus)
{
	char	*s;

	// if (p->exitstatus)
	// 	return;
	s = ft_strjoin("minishell :", p->av[0]);
	if (s)
	{
		if (str)
		{
			s = ft_strjointo(s, " :");
			s = ft_strjointo(s, str);
		}
		if (strerror(err))
		{
			s = ft_strjointo(s, " :");
			s = ft_strjointo(s, strerror(err));
		}
		s = ft_strjointo(s, "\n");
		write(2, s, ft_strlen(s));
		free(s);
	}
	// p->exitstatus = exitstatus;
	mish_exit_status_set(p->mish, exitstatus);
}

int	t_process_is_invalid_option(t_process *p)
{
	int ret = 0;
	char *str;

	ret = 0;
	if ((p->ac > 1) && ft_strlen(p->av[1]) > 1 \
	&& p->av[1][0] == '-' && ft_isalnum(p->av[1][1]))
	{
		ret = 1;
		str = ft_strjoinva(\
		"minishell: ", p->av[0], ": ", p->av[1], ": invalid option\n", NULL);
		if (str == NULL)
		{
			mish_error_add(p->mish, err_malloc, errno, "malloc invalid_opt");
			return (1);
		}
		builtin_error(p, str, 2);
		free (str);
	}
	return (ret);
}
