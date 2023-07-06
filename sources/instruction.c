/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:05:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 18:15:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_swap(t_instruction inst, t_list **lst_a, t_list **lst_b);
static void	exec_pr(t_instruction inst, t_list **lst_a, t_list **lst_b);
static void	print_inst_buffer(t_instruction inst);
static void	print_inst(t_instruction inst);

void	exec_inst(t_instruction inst, t_list **lst_a, t_list **lst_b)
{
	if (inst == sa || inst == sb || inst == ss)
		exec_swap(inst, lst_a, lst_b);
	else if (inst != none)
		exec_pr(inst, lst_a, lst_b);
	print_inst_buffer(inst);
}

static void	exec_swap(t_instruction inst, t_list **lst_a, t_list **lst_b)
{
	t_list	*node_1;
	t_list	*node_2;

	if (inst == sa || inst == ss)
	{
		node_1 = lst_remove_first(lst_a);
		node_2 = lst_remove_first(lst_a);
		ft_lstadd_front(lst_a, node_1);
		ft_lstadd_front(lst_a, node_2);
	}
	if (inst == sb || inst == ss)
	{
		node_1 = lst_remove_first(lst_b);
		node_2 = lst_remove_first(lst_b);
		ft_lstadd_front(lst_b, node_1);
		ft_lstadd_front(lst_b, node_2);
	}
}

static void	exec_pr(t_instruction inst, t_list **lst_a, t_list **lst_b)
{
	if (inst == pa)
		ft_lstadd_front(lst_a, lst_remove_first(lst_b));
	if (inst == pb)
		ft_lstadd_front(lst_b, lst_remove_first(lst_a));
	if (inst == ra || inst == rr)
		ft_lstadd_back(lst_a, lst_remove_first(lst_a));
	if (inst == rb || inst == rr)
		ft_lstadd_back(lst_b, lst_remove_first(lst_b));
	if (inst == rra || inst == rrr)
		ft_lstadd_front(lst_a, lst_remove_last(lst_a));
	if (inst == rrb || inst == rrr)
		ft_lstadd_front(lst_b, lst_remove_last(lst_b));
}

static void	print_inst_buffer(t_instruction inst)
{
	static t_instruction	prev = none;
	t_instruction			print;

	if ((inst == sa && prev == sb) || (inst == sb && prev == sa))
		print = ss;
	else if ((inst == ra && prev == rb) || (inst == rb && prev == ra))
		print = rr;
	else if ((inst == rra && prev == rrb) || (inst == rrb && prev == rra))
		print = rrr;
	else
		print = prev;
	if ((inst == sa && prev == sb) || (inst == sb && prev == sa)
		|| (inst == ra && prev == rb) || (inst == rb && prev == ra)
		|| (inst == rra && prev == rrb) || (inst == rrb && prev == rra))
		prev = none;
	else
		prev = inst;
	print_inst(print);
}

static void	print_inst(t_instruction inst)
{
	if (inst == sa)
		ft_putendl_fd("sa", 1);
	if (inst == sb)
		ft_putendl_fd("sb", 1);
	if (inst == ss)
		ft_putendl_fd("ss", 1);
	if (inst == pa)
		ft_putendl_fd("pa", 1);
	if (inst == pb)
		ft_putendl_fd("pb", 1);
	if (inst == ra)
		ft_putendl_fd("ra", 1);
	if (inst == rb)
		ft_putendl_fd("rb", 1);
	if (inst == rr)
		ft_putendl_fd("rr", 1);
	if (inst == rra)
		ft_putendl_fd("rra", 1);
	if (inst == rrb)
		ft_putendl_fd("rrb", 1);
	if (inst == rrr)
		ft_putendl_fd("rrr", 1);
}
