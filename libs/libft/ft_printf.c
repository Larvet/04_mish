/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:36:27 by bchene            #+#    #+#             */
/*   Updated: 2023/11/18 19:42:58 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnextval(const char c, va_list valist, int ret)
{
	if (c == 'c')
		ret += putvalchar(valist);
	else if (c == 's')
		ret += putvalstring(valist);
	else if (c == 'p')
		ret += putvalpointer(valist);
	else if (c == 'd' || c == 'i')
		ret += putvalint(valist);
	else if (c == 'u')
		ret += putvalunsignedint(valist);
	else if (c == 'x' || c == 'X')
		ret += putvalhexa(valist, c);
	else if (c == '%')
		ret += putvalpercent();
	else if (c == '\0')
		ret = -1;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	valist;
	int		ret;
	int		i;

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			ret = putnextval(format[i], valist, ret);
		}
		else
			ret += write(1, format + i, 1);
		if (format[i])
			i++;
	}
	va_end(valist);
	return (ret);
}
