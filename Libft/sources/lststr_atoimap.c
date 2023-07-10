/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_atoimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:12:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 19:21:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*create_nodes(void *str, void *none);

t_list	*lststr_atoimap(t_list *lst)
{
	return (lst_map(lst, &create_nodes, NULL, &free_wrap));
}

static t_list	*create_nodes(void *str, void *none)
{
	int		*nbr;
	t_list	*new_lst;

	if (none)
		none = NULL;
	nbr = malloc(sizeof(int));
	if (nbr == NULL)
		return (NULL);
	*nbr = ft_atoi(*((const char **)str));
	new_lst = ft_lstnew((void *)nbr);
	if (new_lst == NULL)
		free(nbr);
	return (new_lst);
}
