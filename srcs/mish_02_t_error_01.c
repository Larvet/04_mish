/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_02_t_error_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:14:03 by bchene            #+#    #+#             */
/*   Updated: 2024/05/14 11:18:09 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_error_print(t_error *err)
{
	t_error	*tmp;

	if (err)
	{
		tmp = err;
		while (tmp)
		{
			printf("type=%i \t err_no=%i \t data=%s\n", tmp->type, \
			tmp->err_no, tmp->data);
			tmp = tmp->next;
		}
	}
	else
		printf("(null)\n");
}
