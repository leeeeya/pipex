/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:26:41 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/18 21:26:43 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char **content)
{
	t_list	*list;

	list = (void *)malloc(sizeof (t_list));
	if (!list)
		return (NULL);
	list -> cmd = content;
	list -> next = NULL;
	return (list);
}
