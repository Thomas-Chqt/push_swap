/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:56:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 20:56:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include <libft.h>

# define NO_ARGS -1111
# define DUPLICATE -2222
# define NO_NUM -3333
# define OVERFLOW -4444
# define UNKNOWN_ERROR -5555

int	init_list(int argc, char const *argv[], t_list **lst_a);

#endif // PUSH_SWAP_H