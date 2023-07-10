/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:18:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:21:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	lst_issort(t_list *lst, t_bool (*diff)(void *a, void *b))
{
	t_list	*current;

	if (lst == NULL)
		return (true);
	current = lst;
	while (current->next != NULL)
	{
		if (diff(current->data, current->next->data) == false)
			return (false);
		current = current->next;
	}
	return (true);
}
