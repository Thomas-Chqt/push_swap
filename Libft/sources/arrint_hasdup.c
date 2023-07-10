/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrint_hasdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:41:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 14:23:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *a, void *b);

t_bool	arrint_hasdup(int *array, size_t array_len)
{
	return (arr_hasdup((t_array){(void *)array, array_len, sizeof(int)},
		&is_equal_func));
}

static t_bool	is_equal_func(void *a, void *b)
{
	int	ia;
	int	ib;

	ia = *((int *)a);
	ib = *((int *)b);
	return (ia == ib);
}
