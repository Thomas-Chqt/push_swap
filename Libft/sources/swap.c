/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:55:59 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 12:04:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	swap(void *a, void *b, size_t el_size)
{
	void	*temp;

	temp = malloc(el_size);
	ft_memmove(temp, a, el_size);
	ft_memmove(a, b, el_size);
	ft_memmove(b, temp, el_size);
	free(temp);
}
