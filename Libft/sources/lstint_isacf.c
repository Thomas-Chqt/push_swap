/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_isacf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:29:15 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 15:31:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	lstint_isacf(t_list *lst)
{
	t_bool	res;

	res = lstint_isac(lst);
	ft_lstclear(&lst, free_wrap);
	return (res);
}
