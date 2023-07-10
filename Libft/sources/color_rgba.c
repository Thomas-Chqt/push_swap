/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:40:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:40:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color	color_rgba(t_color_comp r, t_color_comp g, t_color_comp b,
			t_color_comp a)
{
	t_uint32	opacity_component;
	t_uint32	red_component;
	t_uint32	green_component;
	t_uint32	blue_component;

	opacity_component = (t_uint32)a << 24;
	red_component = ((t_uint32)r) << 16;
	green_component = ((t_uint32)g) << 8;
	blue_component = ((t_uint32)b);
	return ((t_color)(opacity_component | red_component
		| green_component | blue_component));
}
