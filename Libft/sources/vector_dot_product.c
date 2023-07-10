/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:27:04 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 17:29:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

float	vector_dot_product(t_vect_3d vector1, t_vect_3d vector2)
{
	return (vector1.x * vector2.x
		+ vector1.y * vector2.y
		+ vector1.z * vector2.z);
}
