/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:01:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:55:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*arr_chr(t_array array, t_bool (*test)(void *, void *), void *data)
{
	t_uint64	index;

	index = arr_ichr(array, test, data);
	if (test(el(array, index), data) == true)
		return (el(array, index));
	return (NULL);
}
