#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"



char	*bito(va_list ap, char c)
{
	if (c == 'x')
		return (ft_itoa_base(va_arg(ap, unsigned int), 16));
	else if (c == 'X')
		return (ft_itoa_base(va_arg(ap, unsigned int), 16));
	else if (c == 'o')
		return (ft_itoa_base(va_arg(ap, unsigned int), 8));
	return ("WAT");
}

int		base(va_list ap, int i, char *s)
{
	char *a;
	int n;
	int l;

	l = 0;
	if (s[i] == '#')
	{
		n = 0;
		if (s[i + 1] == '0')
		{
			n = atoi(&s[i + 2]);
			i += ft_intlen(n);
		}
		l = n;
		a = bito(ap, s[i]);
		n -= ft_strlen(a) + 2;
		if (s[i + 1] == 'X')
			ft_putstr("0X");
		else if (s[i + 1] == 'x')
			 ft_putstr("0x");
		 else if (s[i + 1] == 'o')
			 ft_putstr("00");
		while (--n >= 0)
			ft_putchar('0');
		ft_putstr(a);
	}
	l += ft_strlen(a);
	return (l);
}

int		arg(va_list ap, int i, char *s)
{
	char ch;
	char *a;
	int n;
	int l;

	l = 1;

	if (s[i] == '#')
		l = base(ap, i, s);
	if(s[i] == '%')
		ft_putchar('%');
	if (s[i] == 's')
	{
		a = va_arg(ap, char *);
		ft_putstr(a);
		l = ft_strlen(a);
	}
	if (s[i] == 'p')
	{
		va_arg(ap, void*);
	}
	if(s[i] == 'd' || s[i] == 'i' || s[i] == 'D')
	{
		n = va_arg(ap, int);
		ft_putnbr(n);
		l = ft_num_len(n);
	}
	if (s[i] == 'o' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
	{
		n = va_arg(ap, unsigned int);
		if (s[i] == 'o')
			a = ft_itoa_base(n, 8);
		else if (s[i] == 'u')
			ft_putnbr(n);
		else if (s[i] == 'x')
			a = ft_itoa_base(n, 16);
		l = ft_strlen(a);
		ft_putstr(a);
	}
	if (s[i] == 'c' || s[i] == 'C')
	{
		ch = va_arg(ap, int);
		ft_putchar(ch);
	}
	if(s[i] == '%')
		ft_putchar('%');
	return (l);
}

int ft_printf(char *str, ...)
{
	va_list ap;
	int i;
	int len;

	len = 0;
	i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if(str[i] == '%')
		 arg(ap, ++i, str);
		else
		{
			len++;
			ft_putchar(str[i]);
		}
		i++;
	}
	return(len);
}

int main ()
{
	ft_printf("%s\n","hello");
	printf("%s","hello");
	return(0);
}





