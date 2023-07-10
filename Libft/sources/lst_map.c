/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:59:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *));

t_list	*lst_map(t_list *lst, t_list *(*new_node)(void *, void *), void *data,
			void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_current;
	t_list	*new_lst_current;

	if (lst == NULL || new_node == NULL)
		return (NULL);
	new_lst = new_node(lst->data, data);
	if (new_lst == NULL)
		return (NULL);
	lst_current = lst->next;
	new_lst_current = new_lst;
	while (lst_current != NULL)
	{
		while (new_lst_current->next != NULL)
			new_lst_current = new_lst_current->next;
		new_lst_current->next = new_node(lst_current->data, data);
		if (new_lst_current->next == NULL)
			return (ft_lstclear_wrap(&new_lst, del));
		lst_current = lst_current->next;
	}
	return (new_lst);
}

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
