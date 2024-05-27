/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_math02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:15:43 by bchene            #+#    #+#             */
/*   Updated: 2024/01/17 20:47:17 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	mt_absf(float n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

float	mt_maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mt_minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	mt_signf(float a)
{
	if (a > 0)
		return (1);
	if (a < 0)
		return (-1);
	return (0);
}

float	mt_rangef(float a, float b)
{
	return (mt_maxf(a, b) - mt_minf(a, b));
}
