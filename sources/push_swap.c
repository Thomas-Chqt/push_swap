/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:58:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 20:32:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint32	split_lst_a(t_list **lst_a, size_t lsta_len, t_list **lst_b);
static t_uint32	split_lst_b(t_list **lst_b, size_t lstb_len, t_list **lst_a);


int	init_list(int argc, char const *argv[], t_list **lst_a)
{
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

void	sort_list_a(t_list **lst_a, size_t lsta_len, t_list **lst_b)
{
	t_uint32	new_lsta_len;
	t_uint32	new_lstb_len;
	t_uint32	i;

	if (lst_int_is_asc_sort(*lst_a) || (lsta_len <= 1) || (lsta_len == 2 && *((int *)(*lst_a)->data) <= *((int *)(*lst_a)->next->data)))
		return ;
	if (lsta_len == 2 )
	{
		exec_inst(sa, lst_a, lst_b, NULL);
		return ;
	}
	new_lstb_len = split_lst_a(lst_a, lsta_len, lst_b);
	new_lsta_len = lsta_len - new_lstb_len;
	sort_list_b(lst_b, new_lstb_len, lst_a);
	sort_list_a(lst_a, new_lsta_len, lst_b);
	i = 0;
	while (i < new_lstb_len)
		exec_inst(pa, lst_a, lst_b, &i);	
}

void	sort_list_b(t_list **lst_b, size_t lstb_len, t_list **lst_a)
{
	t_uint32	new_lsta_len;
	t_uint32	new_lstb_len;
	t_uint32	i;

	if (lst_int_is_dec_sort(*lst_b) || (lstb_len == 1) || (lstb_len == 2 && *((int *)(*lst_b)->data) >= *((int *)(*lst_b)->next->data)))
		return ;
	if (lstb_len == 2 )
	{
		exec_inst(sb, lst_a, lst_b, NULL);
		return ;
	}
	new_lsta_len = split_lst_b(lst_b, lstb_len, lst_a);
	new_lstb_len = lstb_len - new_lsta_len;
	sort_list_a(lst_a, new_lsta_len, lst_b);
	sort_list_b(lst_b, new_lstb_len, lst_a);
	i = 0;
	while (i < new_lsta_len)
		exec_inst(pb, lst_a, lst_b, &i);
}

void	exit_error(int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(error_code);
}

static t_uint32	split_lst_a(t_list **lst_a, size_t lsta_len, t_list **lst_b)
{
	t_uint32	i;
	t_uint32	ra_count;
	t_uint32	pb_count;
	int			pivot;
	t_bool		full_liste;

	i = 0;
	ra_count = 0;
	pb_count = 0;
	pivot = lst_find_median_int_free(sub_lst_int(*lst_a, lsta_len));
	full_liste = ((int)lsta_len == ft_lstsize(*lst_a));
	while (i < lsta_len)
	{
		if (*((int *)(*lst_a)->data) <= pivot)
			exec_inst(pb, lst_a, lst_b, &pb_count);
		else
			exec_inst(ra, lst_a, lst_b, &ra_count);
		i++;
	}
	i = 0;
	while (!full_liste && i < ra_count)
		exec_inst(rra, lst_a, lst_b, &i);
	return (pb_count);
}

static t_uint32	split_lst_b(t_list **lst_b, size_t lstb_len, t_list **lst_a)
{
	t_uint32	i;
	t_uint32	rb_count;
	t_uint32	pa_count;
	int			pivot;
	t_bool		full_liste;

	i = 0;
	rb_count = 0;
	pa_count = 0;
	pivot = lst_find_median_int_free(sub_lst_int(*lst_b, lstb_len));
	full_liste = ((int)lstb_len == ft_lstsize(*lst_b));
	while (i < lstb_len)
	{
		if (*((int *)(*lst_b)->data) >= pivot)
			exec_inst(pa, lst_a, lst_b, &pa_count);
		else
			exec_inst(rb, lst_a, lst_b, &rb_count);
		i++;
	}
	i = 0;
	while (!full_liste && i < rb_count)
		exec_inst(rrb, lst_a, lst_b, &i);
	return (pa_count);
}