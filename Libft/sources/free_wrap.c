/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wrap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:42:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 13:52:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	free_wrap(void *ptr)
{
	free(ptr);
}
