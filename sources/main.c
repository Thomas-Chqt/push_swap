/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:00:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/06 18:16:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <libc.h>

int	main(int argc, char const *argv[])
{
	int		ret_val;
	t_list	*list_a;
	t_list	*list_b;

	ret_val = init_list(argc, argv, &list_a);
	if (ret_val != 0)
		exit_error(ret_val);
	return (0);
}
