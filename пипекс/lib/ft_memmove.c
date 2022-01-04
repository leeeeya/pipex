/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:46:00 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:46:03 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (n != 0)
		{
			*((t_byte *)dest + n - 1) = *((t_byte *)src + n - 1);
			n--;
		}
	}
	else if (dest < src)
	{
		while (i != n)
		{
			*((t_byte *) dest + i) = *((t_byte *) src + i);
			i++;
		}
	}
	return (dest);
}
