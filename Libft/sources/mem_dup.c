/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:46:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 15:49:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*mem_dup(void *ptr, size_t len)
{
	void	*new_ptr;

	new_ptr = malloc(len);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, len);
	return (new_ptr);
}
