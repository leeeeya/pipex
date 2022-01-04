/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:07:37 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 23:07:40 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n)
	{
		while ((*str1 == *str2) && (--n != 0) && (*str1) && (*str2))
		{
			str1++;
			str2++;
		}
		return ((unsigned char) *str1 - (unsigned char) *str2);
	}
	return (0);
}
