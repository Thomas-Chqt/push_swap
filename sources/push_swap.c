/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:58:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 21:07:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_not_nbr_wrap(void *str, void *none);
static t_bool	is_overflow_wrap(void *str, void *none);

int	init_list(int argc, char const *argv[], t_list **lst_a)
{
	if (argc < 2)
		return (NO_ARGS);
	if (has_dupl_str((char **)(argv + 1), argc - 1) == true)
		return (DUPLICATE);
	if (contains((t_array){argv + 1, argc - 1, sizeof(char const *)}, NULL, &is_not_nbr_wrap) == true)
		return (NO_NUM);
	if (contains((t_array){argv + 1, argc - 1, sizeof(char const *)}, NULL, &is_overflow_wrap) == true)
		return (OVERFLOW);
	return (0);
}

static t_bool	is_not_nbr_wrap(void *str, void *none)
{
	none = NULL;
	return (!is_number(*((const char **)str)));
}

static t_bool	is_overflow_wrap(void *str, void *none)
{
	long	nbr;

	none = NULL;
	nbr = atoi_long(*((const char **)str));
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (true);
	return (false);
}
