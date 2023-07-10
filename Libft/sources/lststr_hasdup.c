/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_hasdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:07:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 12:59:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *s1, void *s2);

t_bool	lststr_hasdup(t_list *lst)
{
	return (lst_hasdup(lst, &is_equal_func));
}

static t_bool	is_equal_func(void *s1, void *s2)
{
	char	*cs1;
	char	*cs2;

	cs1 = *((char **)s1);
	cs2 = *((char **)s2);
	return (str_cmp(cs1, cs2) == 0);
}
