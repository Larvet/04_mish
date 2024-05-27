/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:06 by bchene            #+#    #+#             */
/*   Updated: 2023/11/06 18:44:47 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ll;

	ll = ft_strlen(little);
	if (ll == 0)
		return ((char *)big);
	i = 0;
	while (len && big[i] && i <= len - ll)
	{
		j = 0;
		while (big[i + j] == little[j] && (j < ll) && little[j])
		{
			if (j == ll - 1)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
