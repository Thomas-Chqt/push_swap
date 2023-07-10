/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:42:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:58:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	lst_delete_if_head(t_list **head, void (*del)(void *))
{
	t_list	*temp;

	temp = *head;
	*head = (*head)->next;
	del(temp->data);
	free(temp);
}

static void	lst_delete_if_mid(t_list *current, void (*del)(void *))
{
	t_list	*temp;

	temp = current->next;
	current->next = current->next->next;
	del(temp->data);
	free(temp);
}

void	lst_delif(t_list **head, void (*del)(void *),
			t_bool (*condition)(void *, void *), void *data)
{
	t_list	*current;

	if (head == NULL || (*head) == NULL || condition == NULL || del == NULL)
		return ;
	if (condition((*head)->data, data) == true)
		lst_delete_if_head(head, del);
	if (head == NULL || (*head) == NULL)
		return ;
	current = *head;
	while (current->next != NULL)
	{
		if (condition(current->next->data, data) == true)
			lst_delete_if_mid(current, del);
		else
			current = current->next;
	}
}
