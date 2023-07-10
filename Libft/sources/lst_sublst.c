/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sublst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:49:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:59:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *));

t_list	*lst_sublst(t_list *lst, size_t new_len, void *(*data_dup)(void *),
			void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*lst_current;
	t_list		*new_lst_current;
	t_uint64	i;

	if (lst == NULL || data_dup == NULL || new_len == 0)
		return (NULL);
	new_lst = lst_nodedup(lst, data_dup);
	if (new_lst == NULL)
		return (NULL);
	lst_current = lst->next;
	new_lst_current = new_lst;
	i = 1;
	while (lst_current != NULL && i < new_len)
	{
		new_lst_current->next = lst_nodedup(lst_current, data_dup);
		if (new_lst_current->next == NULL)
			return (ft_lstclear_wrap(&new_lst, del));
		lst_current = lst_current->next;
		new_lst_current = new_lst_current->next;
		i++;
	}
	return (new_lst);
}

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
