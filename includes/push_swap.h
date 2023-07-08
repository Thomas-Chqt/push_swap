/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:56:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 18:39:19 by tchoquet         ###   ########.fr       */
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

# define DUPLICATE 1
# define NO_NUM 2
# define OVERFLOW 3
# define UNKNOWN_ERROR 4

typedef enum e_instruction	t_instruction;

enum e_instruction {none, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

int		init_list(int argc, char const *argv[], t_list **lst_a);
void	sort_list_a(t_list **lst_a, size_t lsta_len, t_list **lst_b);
void	sort_list_b(t_list **lst_b, size_t lstb_len, t_list **lst_a);
void	exit_error(int error_code);

void	exec_inst(t_instruction inst, t_list **lst_a, t_list **lst_b, t_uint32 *counter);

t_bool	is_not_nbr_wrap(void *str, void *none);
t_bool	is_overflow_wrap(void *str, void *none);
int		lst_clear_wrap(t_list **lst, void (*del)(void *), int ret_val);
t_bool	is_bigger_wrap(void *el, void *com);
t_bool	is_smaller_wrap(void *el, void *com);

#endif // PUSH_SWAP_H