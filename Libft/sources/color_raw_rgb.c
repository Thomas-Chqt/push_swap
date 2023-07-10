/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_raw_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:58:15 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/01 23:03:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color	color_raw_rgb(unsigned int hex)
{
	return (color_rgb((hex & 0xFF0000) >> 16,
			(hex & 0x00FF00) >> 8,
			(hex & 0x0000FF)));
}
