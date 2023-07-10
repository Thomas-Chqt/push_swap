/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_x_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:51:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 12:52:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_mat4x4	mat_x_mat(t_mat4x4 m1, t_mat4x4 m2)
{
	t_mat4x4	matrix;
	t_uint32	c;
	t_uint32	r;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < 4)
		{
			matrix.m[r][c] = m1.m[r][0] * m2.m[0][c]
				+ m1.m[r][1] * m2.m[1][c]
				+ m1.m[r][2] * m2.m[2][c]
				+ m1.m[r][3] * m2.m[3][c];
			r++;
		}
		c++;
	}			
	return (matrix);
}
