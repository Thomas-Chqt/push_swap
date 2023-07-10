/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:37:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/25 17:05:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*watched;
	int		len;

	len = 0;
	watched = lst;
	while (watched != NULL)
	{
		len++;
		watched = watched->next;
	}
	return (len);
}
