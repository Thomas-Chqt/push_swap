/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:00:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/07 19:08:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# ifdef MEMCHECK

#  include <memory_leak_detector.h>

__attribute__((destructor))
static void	destructor(void)
{
	char	*pid;
	char	*cmd;

	print_report();
	pid = ft_itoa(getpid());
	cmd = ft_strjoin("leaks -q ", pid);
	system((const char *)cmd);
	free(pid);
	free(cmd);
}

# endif // MEMCHECK

int	main(int argc, char const *argv[])
{
	int		ret_val;
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	ret_val = init_list(argc, argv, &list_a);
	if (ret_val != 0)
		exit_error(ret_val);
	sort_list_a(&list_a, ft_lstsize(list_a), &list_b);
	exec_inst(none, &list_a, &list_b, NULL);
	ft_lstclear(&list_a, &free_wrap);
	ft_lstclear(&list_b, &free_wrap);
	return (0);
}
