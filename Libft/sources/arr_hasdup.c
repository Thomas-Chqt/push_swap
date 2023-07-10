/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_hasdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:36:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:56:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	arr_hasdup(t_array array, t_bool (*is_equal)(void *, void *))
{
	size_t	i;

	if (array.len < 2)
		return (false);
	i = 1;
	while (i < array.len)
	{
		if (arr_chr((t_array){array.buff, i, array.el_size},
			is_equal, el(array, i)) != NULL)
			return (true);
		i++;
	}
	return (false);
}
