/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:58:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 16:05:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_chr(t_list *lst, t_bool (*test)(void *, void *), void *data)
{
	t_list	*watched;

	watched = lst;
	while (watched != NULL)
	{
		if (test(watched->data, data) == true)
			return (watched);
		watched = watched->next;
	}
	return (NULL);
}
