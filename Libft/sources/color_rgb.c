/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:39:40 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:39:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color	color_rgb(t_color_comp r, t_color_comp g, t_color_comp b)
{
	return (color_rgba(r, g, b, (t_color_comp)0x00));
}
