/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrint_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:57:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 20:02:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	arrint_median(int *array, size_t array_len)
{
	int			*usable_array;
	t_uint64	median_index;
	int			median;

	if (array == NULL || array_len < 3)
		return (0);
	usable_array = arrint_dup(array, array_len);
	if (usable_array == NULL)
		return (0);
	arrint_qcksort(usable_array, array_len);
	median_index = array_len / 2;
	median = usable_array[median_index];
	free(usable_array);
	return (median);
}
