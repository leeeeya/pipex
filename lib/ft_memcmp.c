/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:40:56 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:41:13 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (((t_byte *)s1)[i] == ((t_byte *)s2)[i])
			i++;
		else
			return ((int)(*((t_byte *)s1 + i) - *((t_byte *)s2 + i)));
	}
	return (0);
}
