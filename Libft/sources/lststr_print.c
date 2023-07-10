/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lststr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:55:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/09 12:07:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	print_loop(void	*str_ptr, void *separator);

void	lststr_print(t_list	*lst, char *separator, t_bool endl)
{
	if (lst == NULL)
		return ;
	ft_putstr_fd(*((char **)lst->data), STDOUT_FILENO);
	lst_iterdata(lst->next, &print_loop, separator);
	if (endl == true)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	print_loop(void	*str_ptr, void *separator)
{
	ft_putstr_fd((char *)separator, STDOUT_FILENO);
	ft_putstr_fd(*((char **)str_ptr), STDOUT_FILENO);
}
