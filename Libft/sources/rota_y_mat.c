/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota_y_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:25:42 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/26 16:30:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_mat4x4	rota_y_mat(float angle)
{
	t_mat4x4	matrix;

	matrix = identity_matrix();
	matrix.m[0][0] = cosf(torad(angle));
	matrix.m[0][2] = -sin(torad(angle));
	matrix.m[2][0] = sinf(torad(angle));
	matrix.m[2][2] = cosf(torad(angle));
	return (matrix);
}
