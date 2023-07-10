/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_x_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/26 16:30:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_mat4x4	rota_x_mat(float angle)
{
	t_mat4x4	matrix;

	matrix = identity_matrix();
	matrix.m[1][1] = cosf(torad(angle));
	matrix.m[1][2] = sinf(torad(angle));
	matrix.m[2][1] = -sinf(torad(angle));
	matrix.m[2][2] = cosf(torad(angle));
	return (matrix);
}
