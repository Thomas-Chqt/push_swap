/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:10:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 20:33:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

typedef t_bool	(*t_func)(int, void*);

static t_bool	test_func_wrap(void *nbr, void *data);

t_list	*lstint_chr(t_list *lst, t_bool (*test)(int, void *), void *data)
{
	void	*datas[2];

	datas[0] = test;
	datas[1] = data;
	return (lst_chr(lst, &test_func_wrap, (void *)datas));
}

static t_bool	test_func_wrap(void *nbr, void *data)
{
	int		inbr;
	t_func	test_func;

	inbr = *((int *)nbr);
	test_func = ((void **)data)[0];
	return (test_func(inbr, ((void **)data)[1]));
}
