/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:45:09 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/12 20:45:11 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int d)
{
	int	len;

	len = 0;
	while (d != 0)
	{
		d /= 10;
		len++;
	}
	return (len);
}

char	*check_null(int nul)
{
	char	*res_n;

	res_n = NULL;
	if (nul == 0)
	{
		res_n = (char *) ft_calloc(sizeof(char), 2);
		if (res_n == NULL)
			return (NULL);
		*res_n = '0';
	}
	return (res_n);
}

char	*check_pos(int pos)
{
	char	*res_p;
	int		len_p;

	res_p = NULL;
	if (pos > 0)
	{
		len_p = len(pos);
		res_p = (char *) ft_calloc(sizeof(char), len_p + 1);
		if (res_p == NULL)
			return (NULL);
		while (pos != 0 && len_p != 0)
		{
			res_p[len_p - 1] = (char)(pos % 10 + '0');
			pos /= 10;
			len_p--;
		}
	}
	return (res_p);
}

char	*check_neg(int neg)
{
	char	*res_n;
	int		len_n;

	res_n = NULL;
	if (neg < 0 && neg != INT32_MIN)
	{
		len_n = len(neg);
		res_n = (char *) ft_calloc(sizeof(char), len_n + 2);
		if (res_n == NULL)
			return (NULL);
		res_n[0] = '-';
		neg *= -1;
		while (neg != 0 && len_n != 0)
		{
			res_n[len_n] = (char)(neg % 10 + '0');
			neg /= 10;
			len_n--;
		}
	}
	return (res_n);
}

char	*ft_itoa(int n)
{
	char	*min_int;

	if (n == INT32_MIN)
	{
		min_int = (char *) ft_calloc(sizeof(char), 12);
		if (min_int == NULL)
			return (NULL);
		return (ft_memcpy(min_int, "-2147483648", ft_strlen("-2147483648")));
	}
	else if (n == 0)
		return (check_null(n));
	else if (n > 0)
		return (check_pos(n));
	else
		return (check_neg(n));
}
