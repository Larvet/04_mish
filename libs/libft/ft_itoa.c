/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:39:43 by bchene            #+#    #+#             */
/*   Updated: 2023/11/07 15:05:15 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoalen(int n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*itoa(int n, int size, int sign, char *s)
{
	if (sign)
		s[0] = '-';
	s[size + sign] = '\0';
	while (size)
	{
		s[size + sign - 1] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*s;
	int		sign;

	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	size = 0;
	if (n < 0)
	{
		sign = 1;
		n = -1 * n;
	}
	size = itoalen(n);
	s = malloc(sizeof(char) * (size + sign + 1));
	if (s == NULL)
		return (NULL);
	return (itoa(n, size, sign, s));
}
