/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_substitute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:45:56 by locharve          #+#    #+#             */
/*   Updated: 2024/05/13 18:27:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

char	*copy_sub(char *dst, char *src, char *var, char *sub)
{
	char	*var_addr;
	char	*tmp;
	size_t	len_var;
	size_t	step;

	var_addr = src;
	len_var = ft_strlen(var);
	while (ft_strncmp(var_addr, var, len_var))
		var_addr = ft_strchr(src, '$');
	tmp = ft_strdup(&var_addr[len_var]);
	if (tmp)
	{
		ft_strncpy(dst, src, var_addr - src);
		step = ft_strlen(dst);
		ft_strcpy(&dst[step], sub);
		step = ft_strlen(dst);
		ft_strcpy(&dst[step], tmp);
		free(tmp);
	}
	return (dst);
}

char	*dup_substituting(char *src, char *var, char *sub)
{
	char	*dst;

	dst = ft_calloc(ft_strlen(src) - ft_strlen(var)
			+ ft_strlen(sub) + 1, sizeof(char));
	if (dst)
	{
		dst = copy_sub(dst, src, var, sub);
		free(src);
	}
	return (dst);
}

char	*substitute_0(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;

	dst = NULL;
	sub = ft_strdup("minishell");
	if (sub)
	{
		dst = dup_substituting(src, var, sub);
		if (!dst)
			mish_error_add(mish, err_malloc, errno, "substitute_0");
		free(sub);
	}
	else
		mish_error_add(mish, err_malloc, errno, "substitute_0");
	return (dst);
}

char	*substitute_exit_status(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;

	dst = NULL;
	
	sub = ft_itoa(mish_exit_status_get(mish));
	//sub = ft_itoa(mish->exit_stat);
	if (sub)
	{
		dst = dup_substituting(src, var, sub);
		if (!dst)
			mish_error_add(mish, err_malloc,
					errno, "substitute_exit_status");
		free(sub);
	}
	else
		mish_error_add(mish, err_malloc, errno, "substitute_exit_status");
	return (dst);
}

char	*substitute_var(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;

	dst = NULL;
	sub = get_var_value(mish, var);
	if (sub)
	{
		dst = dup_substituting(src, var, sub);
		if (!dst)
			mish_error_add(mish, err_malloc, errno, "substitute_var");
		free(sub);
	}
	else
		mish_error_add(mish, err_malloc, errno, "substitute_var");
	return (dst);
}
