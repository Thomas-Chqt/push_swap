/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_delifempty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:20:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 12:24:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_empty_str(void *str_ptr, void *none);

void	lststr_delifempty(t_list **head)
{
	lst_delif(head, &free_str_ptr, &is_empty_str, NULL);
}

static t_bool	is_empty_str(void *str_ptr, void *none)
{
	char	*str;

	if (none)
		none = NULL;
	str = *((char **)str_ptr);
	return (str[0] == '\0');
}
