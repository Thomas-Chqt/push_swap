/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:29:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 13:20:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

size_t	arrstr_len(char **array)
{
	size_t	len;

	if (array == NULL)
		return (0);
	len = 0;
	while (array[len] != NULL)
		len++;
	return (len);
}
