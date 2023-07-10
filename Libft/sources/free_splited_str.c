/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splited_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:22:42 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/18 15:34:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	free_splited_str(char **splited_str)
{
	size_t	i;

	if (splited_str == NULL)
		return ;
	i = 0;
	while (splited_str[i] != NULL)
	{
		free(splited_str[i]);
		i++;
	}
	free(splited_str);
}
