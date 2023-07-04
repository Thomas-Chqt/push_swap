/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:58:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/04 16:49:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(int argc, char const *argv[], t_list **lst_a)
{
	t_uint32	i;

	i = argc - 1;
	while (i > 0)
	{
		printf("%s\n", argv[i]);
		i--;
	}
}
