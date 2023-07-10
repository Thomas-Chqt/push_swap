/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_z_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:27:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/26 16:33:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_mat4x4	rota_z_mat(float angle)
{
	t_mat4x4	matrix;

	matrix = identity_matrix();
	matrix.m[0][0] = cosf(torad(angle));
	matrix.m[0][1] = -sinf(torad(angle));
	matrix.m[1][0] = sinf(torad(angle));
	matrix.m[1][1] = cosf(torad(angle));
	return (matrix);
}
