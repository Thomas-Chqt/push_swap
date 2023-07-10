/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:52:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:52:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_vect_3d	cross_product(t_vect_3d p0, t_vect_3d p1, t_vect_3d p2)
{
	t_vect_3d	line1;
	t_vect_3d	line2;

	line1 = new_vect_3d(p1.x - p0.x, p1.y - p0.y, p1.z - p0.z);
	line2 = new_vect_3d(p2.x - p0.x, p2.y - p0.y, p2.z - p0.z);
	return (new_vect_3d(
			line1.y * line2.z - line1.z * line2.y,
			line1.z * line2.x - line1.x * line2.z,
			line1.x * line2.y - line1.y * line2.x
		));
}
