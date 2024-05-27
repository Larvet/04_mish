/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_math01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:48:38 by bchene            #+#    #+#             */
/*   Updated: 2024/01/17 20:47:25 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	mt_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	mt_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	mt_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	mt_sign(int a)
{
	if (a > 0)
		return (1);
	if (a < 0)
		return (-1);
	return (0);
}

int	mt_range(int a, int b)
{
	return (mt_max(a, b) - mt_min(a, b));
}
