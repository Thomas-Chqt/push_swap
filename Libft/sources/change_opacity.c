/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_opacity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:40:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/25 15:56:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color	change_opacity(t_color color, t_color_comp opacity)
{
	t_uint32	opacity_component;
	t_color		new_color;

	opacity_component = (t_uint32)opacity << 24;
	new_color = (t_color)((t_uint32)color | opacity_component);
	return (new_color);
}
