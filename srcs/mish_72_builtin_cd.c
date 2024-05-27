/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_72_builtin_cd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:20:10 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 16:14:36 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static char	*t_process_cd_home_add(t_process *p)
{
	char *path;
	char *home;
	char *newpath;

	path = p->av[1];
	home = mish_env_get(p->mish, "HOME");
	if (path && path[0] == '~')
	{
		if (home == NULL)
		{
			builtin_error(p, "minishell: cd: HOME not set\n", 1);
			return (NULL);
		}
		newpath = ft_strjoin(home, path + 1);
		free (path);
		p->av[1] = newpath;
		return (p->av[1]);
	}
	return (p->av[1]);
}

void	mish_cd(t_process *p)
{
	char	*pwd;
	char	*old;

	pwd = malloc(1024 * sizeof(char));
	getcwd(pwd, 1024);
	if (pwd && p->av[1][0] != '/')
	{
		p->av[1] = ft_strjointoleft(p->av[1], "/");
		p->av[1] = ft_strjointoleft(p->av[1],pwd);
	}
	if (pwd && chdir(p->av[1]))
		builtin_perror(p, errno, p->av[1], 1);
	else if (pwd)
	{
		old = ft_strdup(pwd);
		ft_strfree(&pwd);
		pwd = malloc(1024 * sizeof(char));
		getcwd(pwd, 1024);
		mish_env_add(p->mish, "OLDPWD", old);
		mish_env_add(p->mish, "PWD", pwd);
		//p->exitstatus = 0;
		mish_exit_status_set(p->mish, 0);
		ft_strfree(&old);
	}
	ft_strfree(&pwd);
}

/* cd with only a relative or absolute path */
void	builtin_cd(t_process *p)
{
	if (p->ac == 1)
	{
		ft_freesplit(p->av);
		p->av = ft_split("cd ~", ' ');
		p->ac = 2;
	}
	if (t_process_is_invalid_option(p))
		return;
	if (p->ac == 2)
	{
		if (t_process_cd_home_add(p))
			mish_cd(p);
	}
	else
		builtin_error(p, "minishell: cd: too many arguments\n", 2);
}

/*
> cd ac = 1
	si (HOME == NULL)
		bash: cd: HOME not set > exitstat = 1
	sinon
		cd HOME > exit stat = 0
> av[1][0] == '-'
	bash: cd: -a: invalid option > exit stat = 2
> ac > 2
	bash: cd: too many arguments > exit stat = 1
> cd 
	si ~
		ajout HOME to the left
		ou
		bash: cd: HOME not set > exitstat = 1
	si on accede 
		> exit stat = 0

	si on accede pas
		builtin_perror(p, errno, p->av[1], 1);
*/