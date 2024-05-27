/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:42:16 by locharve          #+#    #+#             */
/*   Updated: 2024/05/27 17:43:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

// Ctrl-D	-> EOF si dans heredoc, exit si la line est vide
//			-> si dans heredoc, p.e "cat << limit (...) oui\n Ctrl-D : cat "limit" 
//			-> contrairement a Ctrl-C

int	g_signal;

void	init_sa(t_sa *sa, void handler(int, siginfo_t *, void *))
{
	sa->sa_sigaction = handler;
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGINT, sa, NULL);
	//signal(SIGQUIT, SIG_IGN);
	sigaction(SIGQUIT, sa, NULL);
}

static void	sigint_action(int pid)
{
	write(1, "\n", 1);
	if (pid)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	// if (g_signal) set exit_stat
}

static void	sigquit_action(int pid)
{
	if (!pid)
	{
		write(1, "Quit (core dumped)\n", 20);
	}
}

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;

	g_signal = sig;
	if (g_signal == SIGINT)
		sigint_action(info->si_pid);
	else if (g_signal == SIGQUIT)
		sigquit_action(info->si_pid);
	return ;
}