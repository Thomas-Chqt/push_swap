/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:00:52 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/25 15:56:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_vect_3d	vector_add(t_vect_3d vector1, t_vect_3d vector2)
{
	return (new_vect_3d(vector1.x + vector2.x,
			vector1.y + vector2.y,
			vector1.z + vector2.z));
}
