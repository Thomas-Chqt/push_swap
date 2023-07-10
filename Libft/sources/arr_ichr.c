/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_ichr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:10:59 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:56:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_uint64	arr_ichr(t_array array, t_bool (*test)(void *, void *), void *data)
{
	size_t	i;

	if (!arr_isvalid(array) || test == NULL)
		return (0);
	i = 0;
	while (i < array.len)
	{
		if (test(el(array, i), data) == true)
			return (i);
		i++;
	}
	if (array.len == 0)
		return (0);
	return (i - 1);
}
