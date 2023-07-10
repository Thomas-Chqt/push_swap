/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tolstmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:09:32 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:56:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *));
static t_list	*lstnew_wrap(void *data, void (*del)(void *));

t_list	*arr_tolstmap(t_array array, void *(*el_dup)(void *),
			void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_wtch;
	size_t	i;

	if (!arr_isvalid(array) || el_dup == NULL || array.len == 0)
		return (NULL);
	new_lst = lstnew_wrap(el_dup(el(array, 0)), del);
	if (new_lst == NULL)
		return (NULL);
	new_lst_wtch = new_lst;
	i = 1;
	while (i < array.len)
	{
		new_lst_wtch->next = lstnew_wrap(el_dup(el(array, i)), del);
		if (new_lst_wtch->next == NULL)
			return (ft_lstclear_wrap(&new_lst, del));
		new_lst_wtch = new_lst_wtch->next;
		i++;
	}
	return (new_lst);
}

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

static t_list	*lstnew_wrap(void *data, void (*del)(void *))
{
	t_list	*new_node;

	if (data == NULL)
		return (NULL);
	new_node = ft_lstnew(data);
	if (new_node == NULL)
		del(data);
	return (new_node);
}
