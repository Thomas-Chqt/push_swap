/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_nodedup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:15:54 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 16:22:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lst_nodedup(t_list *node, void *(*data_dup)(void *))
{
	t_list	*duped_node;

	if (node == NULL)
		return (NULL);
	duped_node = malloc(sizeof(t_list));
	if (duped_node == NULL)
		return (NULL);
	duped_node->data = data_dup(node->data);
	if (duped_node->data == NULL && node->data != NULL)
	{
		free(duped_node);
		return (NULL);
	}
	duped_node->next = NULL;
	return (duped_node);
}
