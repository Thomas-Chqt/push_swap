/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:51:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 14:09:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	diff_func(void *a, void *b);

void	arrint_qcksort(int *array, size_t array_len)
{
	arr_qcksort((t_array){
		.buff = (void *)array,
		.len = array_len,
		.el_size = sizeof(int)
	}, &diff_func);
}

static t_bool	diff_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia <= ib);
}
