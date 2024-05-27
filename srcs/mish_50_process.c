/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_50_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:49:39 by bchene            #+#    #+#             */
/*   Updated: 2024/05/27 15:50:23 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_process_free(t_process *process)
{
	if (process == NULL)
		return ;
	process->av = ft_freesplit(process->av);
	t_process_cmd_free(process);
	t_process_iofile_free(process);
	//t_file_free(&(process->iofiles));
}

void	t_process_print(t_process *p)
{
	if (p == NULL)
	{
		printf("(null)\n");
		return ;
	}
	printf("|||| T_PROCESS\n");
	printf("index = %d\n", p->index);
	printf("line = %s\n", p->line);
	printf("ac = %d\n", p->ac);
	printf("av = ");
	ft_printf_strtab(p->av, p->ac, " ");
	printf("\n");
	t_process_iofile_print(p);
	printf("cmd = %s\n", p->cmd);
	printf("\n");
}
