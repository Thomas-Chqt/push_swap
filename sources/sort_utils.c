/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:00:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 17:26:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint32	split_lst_a(t_list **lst_a, size_t lsta_len, t_list **lst_b)
{
	t_uint32	i;
	t_uint32	ra_count;
	t_uint32	pb_count;
	int			pivot;
	t_bool		full_liste;

	i = 0;
	ra_count = 0;
	pb_count = 0;
	pivot = lstint_medianf(lstint_sublst(*lst_a, lsta_len));
	full_liste = ((int)lsta_len == ft_lstsize(*lst_a));
	while (i < lsta_len && lstint_chr(*lst_a, &is_smaller, &pivot) != NULL)
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

t_uint32	split_lst_b(t_list **lst_b, size_t lstb_len, t_list **lst_a)
{
	t_uint32	i;
	t_uint32	rb_count;
	t_uint32	pa_count;
	int			pivot;
	t_bool		full_liste;

	i = 0;
	rb_count = 0;
	pa_count = 0;
	pivot = lstint_medianf(lstint_sublst(*lst_b, lstb_len));
	full_liste = ((int)lstb_len == ft_lstsize(*lst_b));
	while (i < lstb_len && lstint_chr(*lst_b, &is_bigger, &pivot) != NULL)
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

void	simple_sort_a(t_list **lst_a, size_t lsta_len, t_list **lst_b)
{
	if (lsta_len == 2 )
		exec_inst(sa, lst_a, lst_b, NULL);
}

void	simple_sort_b(t_list **lst_b, size_t lstb_len, t_list **lst_a)
{
	if (lstb_len == 2 )
		exec_inst(sb, lst_a, lst_b, NULL);
}
