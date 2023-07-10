/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:38:35 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:58:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_not_digit_wrapper(void *c, void *none);

t_bool	is_number(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (false);
	i = 0;
	if (str[0] == '-' && ft_isdigit(str[1]))
		i++;
	return (
		!arr_chr((t_array){
			(void *)(str + i),
		ft_strlen(str + i),
		sizeof(char)},
			&is_not_digit_wrapper, NULL));
}

static t_bool	is_not_digit_wrapper(void *c, void *none)
{
	if (none)
		none = NULL;
	return (!ft_isdigit(*((char *)c)));
}
