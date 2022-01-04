/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:02:59 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 23:03:02 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_dst;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	len_dst = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)ft_calloc(len_dst, sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	return (dst);
}
