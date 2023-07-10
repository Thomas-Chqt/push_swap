/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   el.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:31:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 18:17:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	*el(t_array array, size_t index)
{
	return ((void *)(((t_uint8 *)array.buff) + (index * array.el_size)));
}
