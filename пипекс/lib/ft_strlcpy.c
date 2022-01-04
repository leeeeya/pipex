/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:56:51 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/05 22:56:54 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (dstsize != 0)
	{
		while (dstsize != 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			dstsize--;
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
