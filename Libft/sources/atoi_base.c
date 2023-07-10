/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:10:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 12:57:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	skip_white_space(size_t *i, const char *str);
static long	atoi_base_long(const char *str, const char *base);

int	atoi_base(const char *str, const char *base)
{
	return ((int)atoi_base_long(str, base));
}

static long	atoi_base_long(const char *str, const char *base)
{
	char	signe;
	long	nbr;
	size_t	i;

	signe = 1;
	nbr = 0;
	i = 0;
	skip_white_space(&i, str);
	if (str[i] == '-')
		signe *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != 0 && ft_strchr(base, ft_toupper(str[i])) != NULL)
	{
		nbr = (nbr * ft_strlen(base)) + str_ichr((void *)base,
				ft_toupper(str[i]), ft_strlen(base));
		i++;
	}
	return (signe * nbr);
}

static void	skip_white_space(size_t *i, const char *str)
{
	while ((str[*i] >= '\t' && str[*i] <= '\r') || str[*i] == ' ')
		(*i)++;
}
