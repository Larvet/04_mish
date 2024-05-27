/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_substitute_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:15:09 by locharve          #+#    #+#             */
/*   Updated: 2024/05/15 18:15:33 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

char    *mish_substitute_str(t_mish *mish, int f(char *, int), char *str)
{
    int v;

    if (str)
    {
        v = is_there_a_var(str);
        while (v >= 0 && (!f || f(str, v) != 1))
        {
            if (!f || f(str, v) != 1)
			{
                mish_var_dup(mish, &str, &str[v]);
				if (t_error_exist(mish->error))
					break ;
            	v = is_there_a_var(str);
			}
			else
				v = is_there_a_var(&str[v]);
        }
    }
    return (str);
}

char	**mish_substitute_strtab(t_mish *mish, int f(char *, int), char **strtab)
{
	int	i;

	i = 0;
	while (strtab && strtab[i])
	{
		strtab[i] = mish_substitute_str(mish, f, strtab[i]);
		if (!strtab[i])
			break ;
		i++;
	}
	return (strtab);
}