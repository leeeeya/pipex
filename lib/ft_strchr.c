/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:55:58 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:56:01 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	char	ch;

	ch = chr;
	while (*str != ch)
	{
		if (*str == '\0' && ch == '\0')
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
