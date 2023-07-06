/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:58:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 18:26:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(int argc, char const *argv[], t_list **lst_a)
{
	*lst_a = NULL;
	if (argc < 2)
		return (0);
	*lst_a = lst_from_str_array((char **)(argv + 1), argc - 1);
	*lst_a = lst_map_ft_split_clear(lst_a, ' ');
	if (*lst_a == NULL)
		return (lst_clear_wrap(lst_a, &free_wrap, UNKNOWN_ERROR));
	if (lst_has_dupl_str(*lst_a) == true)
		return (lst_clear_wrap(lst_a, &free_wrap, DUPLICATE));
	if (lst_contains(*lst_a, NULL, &is_not_nbr_wrap) == true)
		return (lst_clear_wrap(lst_a, &free_wrap, NO_NUM));
	if (lst_contains(*lst_a, NULL, &is_overflow_wrap) == true)
		return (lst_clear_wrap(lst_a, &free_wrap, OVERFLOW));
	*lst_a = lst_map_ft_atoi_clear(lst_a);
	if (*lst_a == NULL)
		return (lst_clear_wrap(lst_a, &free_wrap, UNKNOWN_ERROR));
	return (0);
}

void	sort_list(t_list *lst, size_t lst_len, t_list *temp_lst)
{
	
}

void	exit_error(int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(error_code);
}
