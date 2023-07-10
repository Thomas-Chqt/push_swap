/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:26:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 13:12:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*arr_best(t_array array, t_bool (*diff)(void *, void *))
{
	t_uint64	i;
	void		*best;

	if (!arr_isvalid(array) || diff == NULL)
		return (NULL);
	best = el(array, 0);
	i = 1;
	while (i < array.len)
	{
		if (diff(best, el(array, i)) == true)
			best = el(array, i);
		i++;
	}
	return (best);
}
