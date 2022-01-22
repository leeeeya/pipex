/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:10:09 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 23:10:10 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int		len;
	char	ch;

	ch = chr;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (*(str + len) == ch)
			return ((char *)str + len);
		else
			len--;
	}
	return (NULL);
}
