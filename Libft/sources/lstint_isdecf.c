/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_isdecf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:30:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 15:32:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	lstint_isdecf(t_list *lst)
{
	t_bool	res;

	res = lstint_isdec(lst);
	ft_lstclear(&lst, free_wrap);
	return (res);
}
