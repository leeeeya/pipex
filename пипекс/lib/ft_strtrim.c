/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:01:44 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/14 19:01:46 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len_s = ft_strlen(s1);
	while (ft_strchr (set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	while (ft_strrchr(set, s1[len_s]) != NULL && s1[i] != '\0')
		len_s--;
	return (ft_substr (s1, i, len_s - i + 1));
}
