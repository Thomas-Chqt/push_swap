/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:36:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/01 22:48:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

unsigned int	atoi_hex(const char *str)
{
	if (str[0] == '0' && str[1] == 'x')
		return ((unsigned int)atoi_base(str + 2, "0123456789ABCDEF"));
	return ((unsigned int)atoi_base(str, "0123456789ABCDEF"));
}
