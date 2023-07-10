/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_foreach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:13:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 13:15:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	arr_foreach(t_array array, void (*func)(void *))
{
	size_t	i;

	if (!arr_isvalid(array) || func == NULL)
		return ;
	i = 0;
	while (i < array.len)
	{
		func(el(array, i));
		i++;
	}
}
