/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:03:58 by bchene            #+#    #+#             */
/*   Updated: 2023/11/18 19:11:31 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putintvarg(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			ret += (int)write(1, "-", 1);
			n *= -1;
		}
		if (n / 10)
			ret += putintvarg(n / 10);
		ret += (int)write(1, &"0123456789"[n % 10], 1);
	}
	return (ret);
}

int	putvalint(va_list valist)
{
	int	ret;
	int	n;

	ret = 0;
	n = (int)va_arg(valist, int);
	ret = putintvarg(n);
	return (ret);
}

int	putunsignedintvarg(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n / 10)
		ret += putunsignedintvarg(n / 10);
	ret += (int)write(1, &"0123456789"[n % 10], 1);
	return (ret);
}

int	putvalunsignedint(va_list valist)
{
	int				ret;
	unsigned int	n;

	ret = 0;
	n = (unsigned int)va_arg(valist, unsigned int);
	ret = putunsignedintvarg(n);
	return (ret);
}
