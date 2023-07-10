/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:33:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:29:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	lstint_median(t_list *lst)
{
	int	*array;
	int	ret;

	array = lstint_toarrmap(lst);
	if (array == NULL)
		return (0);
	ret = arrint_median(array, ft_lstsize(lst));
	free(array);
	return (ret);
}
