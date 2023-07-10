/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:17:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 17:19:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_vect_3d	vector_normalise(t_vect_3d vector)
{
	float	l;

	l = vector_length(vector);
	return (new_vect_3d(vector.x / l, vector.y / l, vector.z / l));
}
