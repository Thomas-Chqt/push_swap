/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:00:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/05 21:06:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <libc.h>

int	main(int argc, char const *argv[])
{
	printf("%d\n", init_list(argc, argv, NULL));
	return (0);
}
