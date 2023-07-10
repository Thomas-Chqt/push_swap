/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:13:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:22:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*memcpy_zero(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		((unsigned char *)src)[i] = 0;
		i++;
	}
	return (dst);
}
