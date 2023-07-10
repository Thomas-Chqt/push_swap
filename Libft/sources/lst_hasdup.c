/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_hasdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:03:59 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 16:07:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	lst_hasdup(t_list *lst, t_bool (*is_equal)(void *, void *))
{
	t_list	*watched;

	if (lst == NULL || lst->next == NULL)
		return (false);
	watched = lst;
	while (watched != NULL)
	{
		if (lst_chr(watched->next, is_equal, watched->data) != NULL)
			return (true);
		watched = watched->next;
	}
	return (false);
}
