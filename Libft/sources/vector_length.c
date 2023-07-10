/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:13:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 17:15:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

float	vector_length(t_vect_3d vector)
{
	return (sqrtf(vector.x * vector.x
			+ vector.y * vector.y
			+ vector.z * vector.z));
}
