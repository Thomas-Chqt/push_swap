/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_x_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:51:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:51:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_vect_3d	vect_x_mat(t_vect_3d vector, t_mat4x4 matrix)
{
	t_vect_3d	new_vector;

	new_vector.x
		= vector.x * matrix.m[0][0]
		+ vector.y * matrix.m[1][0]
		+ vector.z * matrix.m[2][0]
		+ vector.w * matrix.m[3][0];
	new_vector.y
		= vector.x * matrix.m[0][1]
		+ vector.y * matrix.m[1][1]
		+ vector.z * matrix.m[2][1]
		+ vector.w * matrix.m[3][1];
	new_vector.z
		= vector.x * matrix.m[0][2]
		+ vector.y * matrix.m[1][2]
		+ vector.z * matrix.m[2][2]
		+ vector.w * matrix.m[3][2];
	new_vector.w
		= vector.x * matrix.m[0][3]
		+ vector.y * matrix.m[1][3]
		+ vector.z * matrix.m[2][3]
		+ vector.w * matrix.m[3][3];
	return (new_vector);
}
