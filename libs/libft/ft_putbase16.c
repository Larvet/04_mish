/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:07:34 by bchene            #+#    #+#             */
/*   Updated: 2023/11/18 19:11:28 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexavarg(unsigned long long n, char c)
{
	int	ret;

	ret = 0;
	if (n / 16)
		ret += puthexavarg(n / 16, c);
	if (c == 'x')
	{
		ret += (int)write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else if (c == 'X')
	{
		ret += (int)write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	return (ret);
}

int	putvalpointer(va_list valist)
{
	int					ret;
	unsigned long long	n;

	ret = 0;
	n = (unsigned long long)va_arg(valist, unsigned long long);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ret += (int)write(1, "0x", 2);
	ret += puthexavarg(n, 'x');
	return (ret);
}

int	putvalhexa(va_list valist, char c)
{
	int				ret;
	unsigned int	n;

	ret = 0;
	n = (unsigned int)va_arg(valist, unsigned int);
	ret = puthexavarg(n, c);
	return (ret);
}
