/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_splitmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:57:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 12:31:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*create_nodes(void *str, void *c);

t_list	*lststr_splitmap(t_list *lst, char c)
{
	return (lst_map(lst, &create_nodes, &c, &free_str_ptr));
}

static t_list	*create_nodes(void *str, void *c)
{
	char	**splited_str;
	t_list	*lst;

	splited_str = ft_split((*(char **)str), (*(char *)c));
	if (splited_str == NULL)
		return (NULL);
	lst = arrstr_tolstmap(splited_str, arrstr_len(splited_str));
	free_splited_str(splited_str);
	return (lst);
}
