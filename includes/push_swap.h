/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:56:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 17:13:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifdef MEMCHECK
#  include <memory_leak_detector.h>
# endif // MEMCHECK

# include <limits.h>

# include <libft.h>
# include <unistd.h>
# include <libc.h>

typedef enum e_instruction	t_instruction;

enum e_instruction {none, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

int			init_list(int argc, char *argv[], t_list **lst_a);
void		sort_list_a(t_list **lst_a, size_t lsta_len, t_list **lst_b);
void		sort_list_b(t_list **lst_b, size_t lstb_len, t_list **lst_a);

void		exec_inst(t_instruction inst, t_list **lst_a, t_list **lst_b, t_uint32 *counter);

t_bool		is_notnbr(void *str_ptr, void *none);
t_bool		is_overflow(void *str_ptr, void *none);
t_bool		is_empty(void *str_ptr, void *none);
t_bool		is_bigger(int nbr, void *pivot);
t_bool		is_smaller(int nbr, void *pivot);

t_uint32	split_lst_a(t_list **lst_a, size_t lsta_len, t_list **lst_b);
t_uint32	split_lst_b(t_list **lst_b, size_t lstb_len, t_list **lst_a);
void		simple_sort_a(t_list **lst_a, size_t lsta_len, t_list **lst_b);
void		simple_sort_b(t_list **lst_b, size_t lstb_len, t_list **lst_a);

#endif // PUSH_SWAP_H