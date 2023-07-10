/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:06:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 11:48:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*watched;

	watched = lst;
	while (watched != NULL)
	{
		f(watched->data);
		watched = watched->next;
	}
}
