/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_splitmapf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 14:18:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lststr_splitmapf(t_list *lst, char c)
{
	t_list	*new_list;

	new_list = lststr_splitmap(lst, c);
	ft_lstclear(&lst, &free_str_ptr);
	return (new_list);
}
