#include "libft.h"
#include <stdlib.h>

static int ft_count_unsigned_digits(unsigned int n)
{
	unsigned int count;
	long res;

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

char *ft_uitoa(unsigned int n)
{
	int digit_count;
	int has_sign;
	int i;
	char *str;
	long nbr;

	digit_count = ft_count_unsigned_digits(n);
	has_sign = n < 0;
	i = has_sign ? digit_count : digit_count - 1;
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
