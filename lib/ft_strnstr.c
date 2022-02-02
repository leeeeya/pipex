/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:52:26 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/11 20:52:29 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		k = 0;
		while (needle[k] != '\0' && haystack[i] == needle[k] && i < len)
		{
			i++;
			k++;
		}
		if (needle[k] == '\0')
			return (&((char *)haystack)[i - k]);
		i = i - k;
		i++;
	}
	return (NULL);
}
