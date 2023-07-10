/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rmvfrst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:12:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 15:46:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_rmvfrst(t_list **head)
{
	t_list	*temp;

	if (head == NULL || (*head) == NULL)
		return (NULL);
	temp = *head;
	*head = (*head)->next;
	temp->next = NULL;
	return (temp);
}
