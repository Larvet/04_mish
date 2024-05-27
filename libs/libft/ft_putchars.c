/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:06:01 by bchene            #+#    #+#             */
/*   Updated: 2023/11/18 20:20:28 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pfstrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	putvalchar(va_list valist)
{
	int		ret;
	char	c;

	c = (char)va_arg(valist, int);
	ret = (int)write(1, &c, 1);
	return (ret);
}

int	putvalstring(va_list valist)
{
	int			ret;
	const char	*s;

	s = (const char *)va_arg(valist, const char *);
	if (s == NULL)
	{
		ret = (int)write(1, "(null)", 6);
		return (6);
	}
	ret = (int)write(1, s, pfstrlen(s));
	return (ret);
}

int	putvalpercent(void)
{
	int		ret;
	char	c;

	c = '%';
	ret = write(1, &c, 1);
	return (ret);
}
