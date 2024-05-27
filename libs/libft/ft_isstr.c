/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:18:08 by bchene            #+#    #+#             */
/*   Updated: 2024/05/22 21:41:07 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstr_number(const char *str)
{
	if(str == NULL || *str == '\0')
		return (0);
	while((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if(*str == '+' || *str == '-')
		str++;
	while(*str)
	{
		if(!ft_isdigit(*str))
			return(0);
		str++;
	}
	return (1);
}

int	ft_isstr_int(const char *nptr)
{
	int	num;
	int	i;

	if (ft_strcmp(nptr, "-2147483648") == 0)
		return (1);
	if (ft_isstr_number(nptr) == 0)
		return (0);
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	num = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (num > (nptr[i] - '0') + num * 10)
			return (0);
		num = (nptr[i] - '0') + num * 10;
		i++;
	}
	return (1);
}

int	ft_isstr_longlong(const char *nptr)
{
	long long	num;
	int			i;

	if (ft_strcmp(nptr, "-9223372036854775808") == 0)
		return (1);
	if (ft_isstr_number(nptr) == 0)
		return (0);
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	num = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (num > (nptr[i] - '0') + num * 10)
			return (0);
		num = (nptr[i] - '0') + num * 10;
		i++;
	}
	return (1);
}
