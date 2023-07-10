/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:04:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 19:18:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static unsigned short	intlen(int n);

float	ft_atof(const char *str)
{
	int				entier;
	float			virgule;
	unsigned short	v_len;

	entier = (float)ft_atoi(str);
	virgule = (float)ft_atoi(ft_strchr(str, '.') + 1);
	v_len = intlen((int)virgule);
	while (v_len > 0)
	{
		virgule /= 10;
		v_len--;
	}
	if (entier > 0)
		return ((float)entier + virgule);
	return ((float)entier - virgule);
}

static unsigned short	intlen(int n)
{
	unsigned int	nbr;
	unsigned short	len;

	len = 1;
	if (n < 0)
	{
		len++;
		nbr = n * -1;
	}
	else
		nbr = n;
	while ((nbr / 10) > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
