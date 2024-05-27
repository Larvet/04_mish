/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_03_t_env_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:17 by bchene            #+#    #+#             */
/*   Updated: 2024/05/24 16:19:14 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_env	*t_env_getvar(t_env *tenv, char *var)
{
	t_env	*env;

	env = tenv;
	if (env == NULL || var == NULL)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(var, env->var) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*t_env_getdata(t_env *env, char *var)
{
	t_env	*varenv;

	if (env == NULL || var == NULL)
		return (NULL);
	varenv = t_env_getvar(env, var);
	if (varenv)
		return (varenv->data);
	return (NULL);
}

int	t_env_setdata(t_env *env, char *var, char *data)
{
	t_env	*varenv;

	if (var == NULL)
		return (-1);
	varenv = t_env_getvar(env, var);
	if (varenv)
	{
		ft_strfree(&(varenv->data));
		if (data)
			varenv->data = strdup(data);
		else
			varenv->data = NULL;
	}
	else
		t_env_add(&env, var, data);
	return (0);
}

void	t_env_print(t_env *tenv)
{
	while (tenv)
	{
		if (tenv->var && tenv->data)
			printf("%s=%s\n", tenv->var, tenv->data);
		tenv = tenv->next;
	}
}

int	bashvar_name_isvalid(const char *varname)
{
	if (varname == NULL || *varname == '\0')
		return 0;
	if (!ft_isalpha(*varname) && *varname != '_')
		return 0;
	varname++;	
	while (*varname)
	{
		if (!ft_isalnum(*varname) && *varname != '_')
			return 0;
		varname++;
	}	
    return 1;
}

/*
t_env	*t_env_getvar(t_env *tenv, char *var)
{
	t_env	*env;

	env = tenv;
	if (env == NULL || var == NULL)
		return (NULL);
	while (env)
	{
		if ((ft_strncmp(env->str, var, ft_strlen(var)) == 0 && \
		env->str[ft_strlen(var)] == '=' )|| \
		(ft_strncmp(env->str, var, ft_strlen(var)) == 0 && \
		env->str[ft_strlen(var)] == 0 ))
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*t_env_getdata(t_env *env, char *var)
{
	t_env	*varenv;

	if (env == NULL || var == NULL)
		return (NULL);
	varenv = t_env_getvar(env, var);
	if (varenv && varenv->str[ft_strlen(var)] == '=')
			return (varenv->str + ft_strlen(var) + 1);
	return (NULL);
}

int	t_env_setstr(t_env *env, char *var, char *value)
{
	t_env	*varenv;
	char	*str;

	if (var == NULL)
		return (-1);
	str = ft_strempty(NULL);
	str = ft_strjointo(str, var);
	if (value)
	{
		str = ft_strjointo(str, "=");
		str = ft_strjointo(str, value);
	}
	varenv = t_env_getvar(env, var);
	if (varenv && varenv->str)
	{
		free(varenv->str);
		varenv->str = strdup(str);
	}
	else
		t_env_add(&env, str);
	free(str);
	return (0);
}

void	t_env_print(t_env *tenv)
{
	while (tenv)
	{
		if (ft_ischarinstr(tenv->str, '='))
			printf("%s\n", tenv->str);
		tenv = tenv->next;
	}
}
*/