/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_mish_10_env_unset.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:13:08 by bchene            #+#    #+#             */
/*   Updated: 2024/05/24 14:26:37 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*
static void	env_export_str(t_mish *mish, char *str)
{
	int i;
	char *var;
	char *data;

	var = NULL;
	data = NULL;
	i = ft_ischarinstr(str, '=');
	if (i)
	{
		if (i > 2 && str[i - 2] == '+')
		{
			var = ft_strndup(str, i - 2);
			data = ft_strjointo(mish_env_get(mish, var) ,str + i);
		}
		else if(i > 1 && str[0] != '+')
		{
			var = ft_strndup(str, i - 1);
			data = ft_strdup(str + i);
		}
		mish_env_add(mish, var, data);
		ft_strfree(&var);
		ft_strfree(&data);
	}
	else
		mish_env_add(mish, str, NULL);
}
*/

char	*envstr_var_get(char *str)
{
	int i;
	char *var;

	if (str == NULL)
		return (NULL);
	var = NULL;
	i = ft_ischarinstr(str, '=');
	if (i)
		if(i > 1 && str[0] != '+')
			var = ft_strndup(str, i - 1);
		else
			var = ft_strndup(str, i);
	else
		var = strdup(str);
	return (var);
}

/* var=45 ou var+=45 */
char	*envstr_data_get(char *str)
{
	int i;
	char *data;

	if (str == NULL)
		return (NULL);
	data = NULL;
	i = ft_ischarinstr(str, '=');
	if (i)
		data = ft_strdup(str + i);
	else
		return (NULL);
	return (data);	
}

void	mish_env_init(t_mish *mish, char **envp)
{
	int		i;
	char	*var;
	char	*data;

	i = 0;
	while (envp && envp[i])
	{
		var = envstr_var_get(envp[i]);
		data = envstr_data_get(envp[i]);
		t_env_add(&(mish->env), var, data);
		ft_strfree(&var);
		ft_strfree(&data);
		i++;
	}
}

void	mish_env_unset_init(t_mish *mish, char **envp)
{
	int		i;
	char	*value;

	mish_env_init(mish, envp);
	t_env_add(&(mish->unset), "?", "0");
	t_env_add(&(mish->unset), "0", "minishell");
	if (mish_env_get(mish, "SHLVL"))
	{
		i = ft_atoi(mish_env_get(mish, "SHLVL")) + 1;
		value = ft_itoa(i);
		if (value)
		{
			mish_env_set(mish, "SHLVL", value);
			free(value);
		}
		else
			mish_error_add(mish, err_malloc, errno, "SHLVL env init");
	}
}

void	mish_env_unset_free(t_mish *mish)
{
	t_env_free(&(mish->env));
	t_env_free(&(mish->unset));
}

char	*mish_env_unset_get(t_mish *mish, char *var)
{
	char *ret;

	ret = mish_env_get(mish, var);
	if(ret)
		return (ret);
	ret = mish_unset_get(mish, var);
	if(ret)
		return (ret);
	return (NULL);
}

int	mish_env_unset_unset(t_mish *mish, char *var)
{
	if (mish_unset_get(mish, var))
	{
		mish_unset_remove(mish, var);
		return (2);
	}
	if (mish_env_get(mish, var))
	{
		mish_env_remove(mish, var);
		return (1);
	}
	return (0);
}

void	mish_env_unset_print(t_mish *mish)
{
	t_env	*tmp;

	printf("///   env :\n");
	tmp = mish->env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->var, tmp->data);
		tmp = tmp->next;
	}
	printf("///   unset :\n");
	tmp = mish->unset;
	while (tmp)
	{
		printf("%s=%s\n", tmp->var, tmp->data);
		tmp = tmp->next;
	}
}
