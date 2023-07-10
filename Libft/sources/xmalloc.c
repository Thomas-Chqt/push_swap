/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:30:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:59:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*xmalloc(size_t	size, void (*clean_func)(void *), void *data)
{
	void		*ptr;
	static void	(*init_clean_func)(void *);
	static void	*init_data;

	if (size == 0)
	{
		init_clean_func = clean_func;
		init_data = data;
		return (NULL);
	}
	ptr = malloc(size);
	if (ptr == NULL)
	{
		if (clean_func != NULL && clean_func != init_clean_func)
			clean_func(data);
		if (init_clean_func != NULL && init_clean_func != clean_func)
			init_clean_func(init_data);
		exit(-1);
	}
	return (ptr);
}
