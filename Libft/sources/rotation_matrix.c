/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:30:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/26 16:33:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_mat4x4	rotation_matrix(t_vect_3d rotation)
{
	return (mat_x_mat(mat_x_mat(
				rota_x_mat(rotation.x),
				rota_y_mat(rotation.y)),
			rota_z_mat(rotation.z)));
}
