/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:39:15 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:39:17 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	while (n != 0)
	{
		if (*((t_byte *)arr) != (t_byte)c)
		{
			arr++;
			n--;
		}
		else
			return ((void *)arr);
	}
	return (NULL);
}
