/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:59:13 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:59:16 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		count;
	char	*return_str;

	i = 0;
	count = ft_strlen(s);
	return_str = (char *)malloc(sizeof(char) * (count + 1));
	if (return_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		return_str[i] = s[i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}
