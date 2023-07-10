/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrint_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:40:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:57:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	*el_dup(void *el);

int	*arrint_dup(int *array, size_t array_len)
{
	t_array	duped_array;

	duped_array = arr_dup((t_array){(void *)array, array_len, sizeof(int)},
			&el_dup, NULL);
	return ((int *)duped_array.buff);
}

static void	*el_dup(void *el)
{
	return (mem_dup(el, sizeof(int)));
}
