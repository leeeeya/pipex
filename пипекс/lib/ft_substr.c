/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:11:45 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 23:11:48 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substr;
	size_t	sub;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start + 1 > str_len)
		return (ft_calloc(1, 1));
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)ft_calloc((len + 1), sizeof(char));
	if (substr == NULL)
		return (NULL);
	sub = start + len;
	while (start != sub)
	{
		*substr = s[start];
		start++;
		substr++;
	}
	substr -= len;
	return (substr);
}
