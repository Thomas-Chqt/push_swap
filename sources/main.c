/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:00:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:50:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef MEMCHECK

# include <memory_leak_detector.h>

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

#endif // MEMCHECK

int	main(int argc, char const *argv[])
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (init_list(argc, (char **)argv, &list_a) != 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	sort_list_a(&list_a, ft_lstsize(list_a), &list_b);
	exec_inst(none, &list_a, &list_b, NULL);
	ft_lstclear(&list_a, &free_wrap);
	ft_lstclear(&list_b, &free_wrap);
	return (0);
}
