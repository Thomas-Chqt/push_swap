/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:20:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 14:21:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	print_loop(void	*int_ptr, void *separator);

void	lstint_print(t_list	*lst, char *separator, t_bool endl)
{
	if (lst == NULL)
		return ;
	ft_putnbr_fd(*((int *)lst->data), STDOUT_FILENO);
	lst_iterdata(lst->next, &print_loop, separator);
	if (endl == true)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	print_loop(void	*int_ptr, void *separator)
{
	ft_putstr_fd((char *)separator, STDOUT_FILENO);
	ft_putnbr_fd(*((int *)int_ptr), STDOUT_FILENO);
}
