/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:21:42 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/06 21:21:45 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	i_len_dst;

	i_len_dst = ft_strlen(dst);
	i = 0;
	if (dstsize > 0 && i_len_dst < dstsize)
	{
		while ((dstsize > i_len_dst + 1) && (src[i] != '\0'))
		{
			dst[i_len_dst + i] = src[i];
			i++;
			dstsize--;
		}
		dst[i + i_len_dst] = '\0';
	}
	if (dstsize < i_len_dst)
		return (dstsize + ft_strlen(src));
	return (i_len_dst + ft_strlen(src));
}
