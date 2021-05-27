/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazevedo <aazevedo@students.42lisbo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:15:47 by aazevedo          #+#    #+#             */
/*   Updated: 2021/02/23 11:25:47 by aazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_count_digits(int n)
{
	int		count;
	long	res;

	count = 0;
	res = n;
	if (res == 0)
		return (1);
	else if (res < 0)
		res = -res;
	while (res > 0)
	{
		res = res / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa_do(int i, int n, int has_sign, int digit_count)
{
	char	*str;
	long	nbr;

	str = (char *)malloc(sizeof(char) * (has_sign + digit_count + 1));
	if (!str)
		return (0);
	nbr = n;
	if (has_sign)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (i >= has_sign)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[(has_sign + digit_count)] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int		digit_count;
	int		has_sign;
	int		i;
	char	*str;

	digit_count = ft_count_digits(n);
	has_sign = 0;
	i = digit_count - 1;
	if (n < 0)
	{
		has_sign = 1;
		i = digit_count;
	}
	return (ft_itoa_do(i, n, has_sign, digit_count));
}
