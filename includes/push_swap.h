/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:56:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 18:19:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	sort_list(t_list *lst, size_t lst_len, t_list *temp_lst);
void	exit_error(int error_code);

void	exec_inst(t_instruction inst, t_list **lst_a, t_list **lst_b);

t_bool	is_not_nbr_wrap(void *str, void *none);
t_bool	is_overflow_wrap(void *str, void *none);
int		lst_clear_wrap(t_list **lst, void (*del)(void *), int ret_val);

#endif // PUSH_SWAP_H