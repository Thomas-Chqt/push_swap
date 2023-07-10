/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_sublst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:51:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:34:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	*data_dup(void *data);

t_list	*lstint_sublst(t_list *lst, size_t new_len)
{
	return (lst_sublst(lst, new_len, &data_dup, &free_wrap));
}

static void	*data_dup(void *data)
{
	return (mem_dup(data, sizeof(int)));
}
