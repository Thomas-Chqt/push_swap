/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:58:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 18:47:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(int argc, char *argv[], t_list **lst_a)
{
	if (argc < 2)
		return (0);
	*lst_a = arrstr_tolstmap(argv + 1, argc - 1);
	if (lst_chr(*lst_a, &is_empty, NULL) == NULL)
	{
		*lst_a = lststr_splitmapf(*lst_a, ' ');
		if (lst_chr(*lst_a, &is_notnbr, NULL) == NULL && lst_chr(*lst_a, &is_overflow, NULL) == NULL && lststr_hasdup(*lst_a) == false)
		{
			*lst_a = lststr_atoimapf(*lst_a);
			return (0);
		}
	}	
	ft_lstclear(lst_a, &free_str_ptr);
	return (-1);
}

void	sort_list_a(t_list **lst_a, size_t lsta_len, t_list **lst_b)
{
	t_uint32	new_lsta_len;
	t_uint32	new_lstb_len;
	t_uint32	i;

	if (lstint_isacf(lstint_sublst(*lst_a, lsta_len)))
		return ;
	if (lsta_len < 3)
		return (simple_sort_a(lst_a, lsta_len, lst_b));
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

	if (lstint_isdecf(lstint_sublst(*lst_b, lstb_len)))
		return ;
	if (lstb_len < 3)
		return (simple_sort_b(lst_b, lstb_len, lst_a));
	new_lsta_len = split_lst_b(lst_b, lstb_len, lst_a);
	new_lstb_len = lstb_len - new_lsta_len;
	sort_list_a(lst_a, new_lsta_len, lst_b);
	sort_list_b(lst_b, new_lstb_len, lst_a);
	i = 0;
	while (i < new_lsta_len)
		exec_inst(pb, lst_a, lst_b, &i);
}
