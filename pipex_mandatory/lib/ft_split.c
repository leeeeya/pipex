/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:17:29 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/17 00:17:31 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int	i;
	int	flag;
	int	count;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		if (s[i] != c && flag == 1)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_word_len(char const **str, char ch)
{
	int	count_ch;

	count_ch = 0;
	while (**str == ch)
		*str += 1;
	while (**str != '\0' && **str != ch)
	{
		*str += 1;
		count_ch++;
	}
	return (count_ch);
}

void	ft_copy(char **res1, const char *s, char cr, int word_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0' && i != word_count)
	{
		while (*s == cr)
			s++;
		while (*s != cr && *s != '\0')
		{
			res1[i][j] = *(char *)s;
			s++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	*ft_free_arr(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	int			i;
	const char	*s1;
	int			word_count;

	i = 0;
	if (s == NULL)
		return (NULL);
	s1 = s;
	word_count = ft_word_count(s, c);
	res = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (i != word_count && *s1 != '\0')
	{
		res[i] = (char *)ft_calloc(ft_word_len(&s1, c) + 1, sizeof (char));
		if (res[i] == NULL)
			return (ft_free_arr(res));
		i++;
	}
	ft_copy(res, s, c, word_count);
	return (res);
}
