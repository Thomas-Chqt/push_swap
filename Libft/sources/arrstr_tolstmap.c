/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_tolstmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:50:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 17:57:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	*el_dup(void *el);

t_list	*arrstr_tolstmap(char **array, size_t array_len)
{
	return (
		arr_tolstmap((t_array){
			.buff = array,
			.len = array_len,
			.el_size = sizeof(char *)
		}, &el_dup, &free_str_ptr)
	);
}

static void	*el_dup(void *el)
{
	char	*str;
	char	*duped_str;
	char	**duped_str_ptr;

	str = *((char **)el);
	duped_str = ft_strdup(str);
	if (duped_str == NULL)
		return (NULL);
	duped_str_ptr = malloc(sizeof(char *));
	if (duped_str_ptr == NULL)
		free(duped_str);
	else
		*duped_str_ptr = duped_str;
	return (duped_str_ptr);
}
