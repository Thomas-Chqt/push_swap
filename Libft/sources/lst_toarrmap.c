/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_toarrmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:06:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:59:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_array	ret_error(t_array array, t_uint64 len, void (*free_el)(void *));

t_array	lst_toarrmap(t_list *lst, size_t el_size, void *(*data_dup)(void *),
			void (*free_el)(void *))
{
	t_array	array;
	void	*duped_el;
	t_list	*current;
	size_t	i;

	if (lst == NULL || data_dup == NULL)
		return ((t_array){.buff = NULL});
	array.len = ft_lstsize(lst);
	array.el_size = el_size;
	array.buff = malloc(el_size * array.len);
	if (array.buff == NULL)
		return ((t_array){.buff = NULL});
	current = lst;
	i = 0;
	while (i < array.len)
	{
		duped_el = data_dup(current->data);
		if (duped_el == NULL)
			return (ret_error(array, i, free_el));
		ft_memcpy(el(array, i), duped_el, array.el_size);
		free(duped_el);
		current = current->next;
		i++;
	}
	return (array);
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
