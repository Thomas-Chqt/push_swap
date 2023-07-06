/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:46:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 18:16:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_not_nbr_wrap(void *str, void *none)
{
	none = NULL;
	return (!is_number((const char *)str));
}

t_bool	is_overflow_wrap(void *str, void *none)
{
	long	nbr;

	none = NULL;
	nbr = atoi_long((const char *)str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (true);
	return (false);
}

int	lst_clear_wrap(t_list **lst, void (*del)(void *), int ret_val)
{
	ft_lstclear(lst, del);
	return (ret_val);
}
