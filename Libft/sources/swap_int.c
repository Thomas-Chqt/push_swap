/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:01:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 12:04:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	swap_int(int *a, int *b)
{
	swap((void *)a, (void *)b, sizeof(int));
}
