/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_int_is_asc_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:27:40 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:33:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	diff_func(void *a, void *b);

t_bool	lstint_isac(t_list *lst)
{
	return (lst_issort(lst, &diff_func));
}

static t_bool	diff_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia <= ib);
}
