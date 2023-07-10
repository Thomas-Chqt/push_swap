/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:22:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 17:24:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_vect_3d	vector_sub(t_vect_3d vector1, t_vect_3d vector2)
{
	return (new_vect_3d(vector1.x - vector2.x,
			vector1.y - vector2.y,
			vector1.z - vector2.z));
}
