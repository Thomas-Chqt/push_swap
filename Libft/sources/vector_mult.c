/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:40:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/24 18:40:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_vect_3d	vector_mult(t_vect_3d v1, float k)
{
	return ((t_vect_3d){v1.x * k, v1.y * k, v1.z * k, v1.w * k});
}
