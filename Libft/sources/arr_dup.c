/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:33:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 17:30:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_array	ret_error(t_array array, t_uint64 len, void (*free_el)(void *));

t_array	arr_dup(t_array array, void *(*el_dup)(void *), void (*free_el)(void *))
{	
	t_array		new_array;
	void		*duped_el;
	t_uint64	i;

	if (!arr_isvalid(array) || el_dup == NULL || array.len == 0)
		return ((t_array){.buff = NULL});
	new_array = (t_array){
		.buff = malloc(array.el_size * array.len),
		.len = array.len,
		.el_size = array.el_size
	};
	if (new_array.buff == NULL)
		return ((t_array){.buff = NULL});
	i = 0;
	while (i < array.len)
	{
		duped_el = el_dup(el(array, i));
		if (duped_el == NULL)
			return (ret_error(array, i, free_el));
		ft_memcpy(el(new_array, i), duped_el, array.el_size);
		free(duped_el);
		i++;
	}
	return (new_array);
}

static t_array	ret_error(t_array array, t_uint64 len, void (*free_el)(void *))
{
	t_uint64	i;

	if (free_el == NULL)
	{
		free(array.buff);
		return ((t_array){.buff = NULL});
	}
	i = 0;
	while (i < len)
	{
		free(el(array, i));
		i++;
	}
	free(array.buff);
	return ((t_array){.buff = NULL});
}
