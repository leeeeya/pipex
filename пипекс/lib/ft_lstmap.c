/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:55:25 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/20 23:55:27 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_res;
	t_list	*tmp_lst;

	lst_res = NULL;
	if (lst == NULL)
		return (NULL);
	tmp_lst = lst;
	lst_res = ft_lstnew(f(tmp_lst->content));
	if (lst_res == NULL)
		return (NULL);
	while (tmp_lst->next != NULL)
	{
		tmp_lst = tmp_lst->next;
		ft_lstadd_back(&lst_res, ft_lstnew(f(tmp_lst->content)));
	}
	if (ft_lstsize(lst) > ft_lstsize(lst_res))
	{
		ft_lstclear(&lst_res, del);
		return (NULL);
	}
	return (lst_res);
}
