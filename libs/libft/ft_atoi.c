/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:25 by bchene            #+#    #+#             */
/*   Updated: 2024/05/22 21:33:40 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
		num = (nptr[i++] - '0') + num * 10;
	return (sign * num);
}

long long	ft_atoll(const char *nptr)
{
	long long	num;
	int			sign;
	int			i;

	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
		num = (nptr[i++] - '0') + num * 10;
	return (sign * num);
}
