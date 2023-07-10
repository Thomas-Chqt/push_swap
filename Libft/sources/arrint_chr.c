/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrint_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:19:52 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 20:02:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	test_func_wrap(void *nbr, void *data);

int	*arrint_chr(int *array, size_t array_len, t_bool (*test)(int, void *), void *data)
{
	void	*datas[2];

	datas[0] = test;
	datas[1] = data;
	return (arr_chr((t_array){(void *)array, array_len, sizeof(int)}, &test_func_wrap, (void *)datas));
}

static t_bool	test_func_wrap(void *nbr, void *data)
{
	int		inbr;
	t_bool	(*test_func)(int, void *);

	inbr = *((int *)nbr);
	test_func = ((void **)data)[0];
	return (test_func(inbr, ((void **)data)[1]));
}
