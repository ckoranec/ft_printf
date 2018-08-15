#include "libft.h"

void	ft_longint(long long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_longint(-n);
	}
	else if (n > 9)
	{
		ft_longint(n / 10);
		ft_longint(n % 10);
	}
	else
		ft_putchar(n + '0');
}
