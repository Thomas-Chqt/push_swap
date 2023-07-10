/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blue_comp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:42:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:42:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color_comp	get_blue_comp(t_color color)
{
	return ((t_color_comp)(((t_uint32)color) & 0x000000FF));
}
