/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:00:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:09:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_tl_cases	find_tl_case(t_list *lst);

void	simple_sort_a(t_list **lst_a, size_t lsta_len, t_list **lst_b)
{
	if (lsta_len == 2)
		return (exec_inst(sa, lst_a, lst_b, NULL));
	if (find_tl_case(*lst_a) == _321 || find_tl_case(*lst_a) == _132)
		exec_inst(sa, lst_a, lst_b, NULL);
	if (find_tl_case(*lst_a) == _231)
		return (exec_inst(rra, lst_a, lst_b, NULL));
	if (find_tl_case(*lst_a) == _312)
		return (exec_inst(ra, lst_a, lst_b, NULL));
	return (exec_inst(sa, lst_a, lst_b, NULL));
}

void	simple_sort_b(t_list **lst_b, size_t lstb_len, t_list **lst_a)
{
	if (lstb_len == 2)
		return (exec_inst(sb, lst_a, lst_b, NULL));
	if (find_tl_case(*lst_b) == _123 || find_tl_case(*lst_b) == _312)
		exec_inst(sb, lst_a, lst_b, NULL);
	if (find_tl_case(*lst_b) == _213)
		return (exec_inst(rrb, lst_a, lst_b, NULL));
	if (find_tl_case(*lst_b) == _132)
		return (exec_inst(rb, lst_a, lst_b, NULL));
	return (exec_inst(sb, lst_a, lst_b, NULL));
}

static t_tl_cases	find_tl_case(t_list *lst)
{
	if (lstint_isac(lst))
		return (_123);
	if (*(int *)lst->data < *(int *)lst->next->data
		&& *(int *)lst->data < *(int *)lst->next->next->data)
		return (_132);
	if (lstint_isdec(lst))
		return (_321);
	if (*(int *)lst->data > *(int *)lst->next->data
		&& *(int *)lst->data > *(int *)lst->next->next->data)
		return (_312);
	if (lstint_isac(lst->next))
		return (_213);
	return (_231);
}
