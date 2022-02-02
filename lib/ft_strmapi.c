/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:06:31 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 23:06:33 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof (char));
	if (res == NULL)
		return (NULL);
	ft_bzero(res, ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
