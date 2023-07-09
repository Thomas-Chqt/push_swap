/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:46:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 17:16:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_notnbr(void *str_ptr, void *none)
{
	if (none)
		none = NULL;
	return (!is_number(*((const char **)str_ptr)));
}

t_bool	is_overflow(void *str_ptr, void *none)
{
	long	nbr;

	if (none)
		none = NULL;
	nbr = atoi_long(*((const char **)str_ptr));
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (true);
	return (false);
}

t_bool	is_empty(void *str_ptr, void *none)
{
	char	*trimed;
	t_bool	ret;

	if (none)
		none = NULL;
	trimed = ft_strtrim(*((const char **)str_ptr), " \t");
	ret = trimed[0] == '\0';
	free(trimed);
	return (ret);
}

t_bool	is_bigger(int nbr, void *pivot)
{
	return (nbr >= *((int *)pivot));
}

t_bool	is_smaller(int nbr, void *pivot)
{
	return (nbr <= *((int *)pivot));
}