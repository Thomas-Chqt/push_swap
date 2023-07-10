/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opacity_comp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:41:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:41:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color_comp	get_opacity_comp(t_color color)
{
	return ((t_color_comp)((((t_uint32)color) & 0xFF000000) >> 24));
}
