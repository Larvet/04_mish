/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:18:57 by bchene            #+#    #+#             */
/*   Updated: 2024/01/18 21:48:07 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"

int	randint(void)
{
	int	urandomfd;
	int	randomint;

	urandomfd = open("/dev/urandom", O_RDONLY);
	if (urandomfd < 0)
	{
		ft_printf("Error opening file /dev/urandom");
		exit(EXIT_FAILURE);
	}
	if (read(urandomfd, &randomint, sizeof(randomint)) != sizeof(randomint))
	{
		ft_printf("Error reading file /dev/urandom");
		close(urandomfd);
		exit(EXIT_FAILURE);
	}
	close(urandomfd);
	return (randomint);
}

unsigned int	randuint(void)
{
	int				urandomfd;
	unsigned int	randomint;

	urandomfd = open("/dev/urandom", O_RDONLY);
	if (urandomfd < 0)
	{
		ft_printf("Error opening file /dev/urandom");
		exit(EXIT_FAILURE);
	}
	if (read(urandomfd, &randomint, sizeof(randomint)) != sizeof(randomint))
	{
		ft_printf("Error reading file /dev/urandom");
		close(urandomfd);
		exit(EXIT_FAILURE);
	}
	close(urandomfd);
	return (randomint);
}

int	randintrange(int a, int b)
{
	unsigned int	rand;
	float			fact;

	rand = randuint();
	fact = rand / __UINT32_MAX__;
	rand = fact * (mt_max(a, b) - mt_min(a, b));
	return (rand);
}
