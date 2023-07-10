/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:39:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/26 16:40:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_mat4x4	translate_matrix(t_vect_3d translation)
{
	t_mat4x4	matrix;

	matrix = identity_matrix();
	matrix.m[3][0] = translation.x;
	matrix.m[3][1] = translation.y;
	matrix.m[3][2] = translation.z;
	return (matrix);
}
