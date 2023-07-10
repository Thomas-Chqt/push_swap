/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_atoimapf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:28:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 14:18:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lststr_atoimapf(t_list *lst)
{
	t_list	*new_list;

	new_list = lststr_atoimap(lst);
	ft_lstclear(&lst, &free_str_ptr);
	return (new_list);
}
