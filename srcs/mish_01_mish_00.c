/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 17:25:48 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_init(t_mish *mish, char **envp)
{
	ft_bzero(mish, sizeof(t_mish));
	mish_env_unset_init(mish, envp);

	init_sa(&mish->sa, handle_signal);

	return (t_error_exist(mish->error));
}

t_err_type	mish_init_bis(t_mish *mish, char **envp)
{
	mish->error = NULL;
	mish->prompt = NULL;
	mish->line = NULL;
	mish->splitline = NULL;
	mish->nb = 0;
	mish->p = NULL;
	mish->fds = NULL;
	mish->pid = NULL;
	mish_env_unset_init(mish, envp);
	mish->pathlist = NULL;
	return (t_error_exist(mish->error));
}

void	mish_free(t_mish *mish, int isroot)
{
	if (isroot)
		mish_heredocs_unlink(mish);
	if (mish->error)
		t_error_lst_free(&(mish->error));
	if (mish->prompt)
		free(mish->prompt);
	if (mish->line)
		free(mish->line);
	if (mish->splitline)
		ft_freesplit(mish->splitline);
	if (mish->p)
		mish_p_free(mish);
	if (mish->fds)
		mish_fds_free(mish);
	if (mish->pid)
		free(mish->pid);
	mish->nb = mish_exit_status_get(mish);
	if (mish->env || mish->unset)
		mish_env_unset_free(mish);
	if (mish->pathlist)
		ft_freesplit(mish->pathlist);
	rl_clear_history();
}

void	mish_reset(t_mish *mish)
{
	mish_heredocs_unlink(mish);
	if (mish->splitline)
		mish->splitline = ft_freesplit(mish->splitline);
	if (mish->p)
		mish_p_free(mish);
	if (mish->fds)
		mish_fds_free(mish);
	if (mish->pid)
	{
		free(mish->pid);
		mish->pid = NULL;
	}
	if (mish->pathlist)
		mish->pathlist = ft_freesplit(mish->pathlist);
	mish->nb = 0;
}

void	mish_print(t_mish *mish)
{
	printf("\n////////////////////////// \n");
	printf("///   mish_print ///////// \n");
	printf("///   error : \n");
	t_error_print(mish->error);
	printf("///   prompt = %s\n", mish->prompt);
	printf("///   line = %s\n", mish->line);
	printf("///   splitline : \n");
	ft_print_split(mish->splitline);
	printf("///   nb = %i\n", mish->nb);
	printf("///   process : \n");
	mish_p_print(mish);
	printf("///   fds : \n");
	mish_fds_print(mish);
	printf("///   pid = ");
	mish_pid_print(mish);
	/*	//printf("///   env :\n");
		//t_env_print(mish->env); */
	printf("///   unset :\n");
	t_env_print(mish->unset);
	printf("///   pathlist : \n");
	ft_print_split(mish->pathlist);
	printf("///   mish_print ///////// \n");
	printf("////////////////////////// \n\n");
}
