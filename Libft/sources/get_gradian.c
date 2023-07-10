/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gradian.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:42:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/25 15:56:12 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_color	get_gradian(t_color src, t_color dst, t_uint32 max, t_uint32 step)
{
	int	dr;
	int	dg;
	int	db;

	if (step == 0)
		return (src);
	dr = (int)get_red_comp(dst) - (int)get_red_comp(src);
	dg = (int)get_green_comp(dst) - (int)get_green_comp(src);
	db = (int)get_blue_comp(dst) - (int)get_blue_comp(src);
	return (
		color_rgb(
			(t_color_comp)round((float)get_red_comp(src)
				+ (((float)dr / (float)max) * (float)step)),
			(t_color_comp)round((float)get_green_comp(src)
				+ (((float)dg / (float)max) * (float)step)),
			(t_color_comp)round((float)get_blue_comp(src)
				+ (((float)db / (float)max) * (float)step))
		)
	);
}
