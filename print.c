/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:44:51 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/20 22:15:04 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	char	*str;
	int		i;
	wchar_t	*ptr;
	int		prec;
	int		pr2;

	prec = 0;
	pr2 = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = ft_strlen(str);
	(lenmod->blen || lenmod->alen) ? prec = cheese(varg, lenmod, 0, str) : 0;
	if (lenmod->minus == 1)
	{
		if (lenmod->minusnumber <= i)
		{
			ft_putstr(str);
			return (i);
		}
		else if (lenmod->minusnumber >= i)
		{
			if (i > lenmod->alen)
			{
				write(1, str, lenmod->alen);
				prec = lenmod->alen;
			}
			else
			{
				ft_putstr(str);
				prec = i;
			}
			while (prec < lenmod->minusnumber)
			{
				ft_putchar(' ');
				prec++;
			}
			return ((lenmod->blen));
		}
	}
	else if (lenmod->l == 1)
	{
		ptr = va_arg(ap, wchar_t *);
		return (putwstr(ptr));
	}
	else
		ft_putstr(str);
	return (ft_strlen(str) + prec);
}

int	print_o_x(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	int			base;
	int			i;
	intmax_t	num;
	int			len;

	num = 0;
	i = 0;
	len = 0;
	if (varg->o == 1)
		base = 8;
	else if (varg->x == 1)
		base = 16;
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if (lenmod->l == 1)
			num = (long)va_arg(ap, intmax_t);
		else
			num = (long long)va_arg(ap, intmax_t);
	}
	else if (lenmod->h == 1)
		num = (char)va_arg(ap, int);
	else if (lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if (lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (long long)va_arg(ap, long long);
	if (lenmod->blen < 0 || lenmod->alen < 0)
		cheese(varg, lenmod, 0, ft_itoa_base(num, base));
	if (lenmod->plus == 1)
	{
		if (num > 0)
		{
			ft_putchar('+');
			return (ft_strlen(ft_itoa_base(num + 1, base)));
		}
	}
	if (lenmod->zero == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->zeronumber)
		{
			ft_putnbr(0);
			i++;
		}
	}
	if (lenmod->pound == 1)
	{
		if (varg->x || varg->bigx)
		{
			ft_putstr("0X");
			len = 2;
		}
		else
		{
			if (num != 0)
			{
				ft_putchar('0');
				len = 1;
			}
		}
	}
	if (varg->bigo == 1 || varg->bigx == 1)
	{
		if (varg->bigo == 1)
			base = 8;
		else
			base = 16;
		ft_putstr(supper(ft_itoa_base(num, base)));
	}
	else
		ft_putstr(ft_itoa_base(num, base));
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (ft_strlen(ft_itoa_base(num, base)) + len);
}

int	print_c(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	wchar_t	fatc;
	int		i;
	char	c;

	c = '\0';
	i = 0;
	if (varg->bigc == 1)
	{
		fatc = va_arg(ap, wchar_t);
		ft_putchar(fatc);
		return (1);
	}
	else
		c = va_arg(ap, int);
	if (c == '\0')
	{
		ft_putchar('\0');
		return (1);
	}
	if (lenmod->blen > 0 || lenmod->alen > 0)
		cheese(varg, lenmod, 0, NULL);
	print_c2(*varg, *lenmod, ap, i)
}

int	print_c2(t_varg *varg, t_lenmod *lenmod, va_list ap, int i)
{
	if (lenmod->minus == 1)
	{
		if (lenmod->minusnumber <= i)
		{
			ft_putchar(c);
			return (1);
		}
		else if (lenmod->minusnumber >= i)
		{
			ft_putchar(c);
			while (i < lenmod->minusnumber)
			{
				ft_putchar(' ');
				i++;
			}
			return (i + 1);
		}
	}
	else
		ft_putchar(c);
	return (1);
}

int	print_p(va_list ap)
{
	unsigned long long bacon;

	bacon = va_arg(ap, long long);
	ft_putchar('0');
	ft_putchar('x');
	if (bacon == 0)
	{
		ft_putchar('0');
		return (3);
	}
	else
		ft_putstr(ft_itoa_base(bacon, 16));
	return (ft_strlen(ft_itoa_base(bacon, 16)) + 2);
}

int	print_u(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	int			i;
	intmax_t	num;

	num = 0;
	i = 0;
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if (lenmod->l == 1)
			num = (unsigned long)va_arg(ap, intmax_t);
		else
			num = (unsigned long long)va_arg(ap, intmax_t);
	}
	else if (lenmod->h == 1)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if (lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (unsigned int)va_arg(ap, int);
	if (lenmod->blen < 0 || lenmod->alen < 0)
		cheese(varg, lenmod, num, NULL);
	if (lenmod->plus == 1)
	{
		if (num > 0)
		{
			ft_putchar('+');
			return (ft_strlen(ft_ultoa_base(num, 10)) + 1);
		}
	}
	if (lenmod->zero == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->zeronumber)
		{
			ft_putnbr(0);
			i++;
		}
	}
	ft_putstr(ft_ultoa_base(num, 10));
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (ft_strlen(ft_ultoa_base(num, 10)));
}

int	print_bigd(va_list ap)
{
	long long num;

	num = va_arg(ap, long long);
	ft_longint(num);
	return (ft_strlen(ft_itoa_base(num, 10)));
}

int	print_bigs(va_list ap)
{
	int		i;
	wchar_t	*s;

	i = 0;
	s = va_arg(ap, wchar_t *);
	putwstr(s);
	while (s[i])
		i++;
	return (i);
}

int	print_d_i(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	int			i;
	intmax_t	num;
	int			j;
	int			prec;
	int			pr2;

	j = 0;
	num = 0;
	i = 0;
	prec = 0;
	pr2 = 0;
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if (lenmod->l == 1)
			num = (long)va_arg(ap, intmax_t);
		else
			num = (long long)va_arg(ap, intmax_t);
	}
	else if (lenmod->h == 1)
		num = (char)va_arg(ap, int);
	else if (lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if (lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (int)va_arg(ap, int);
	if (lenmod->space == 1)
	{
		if (num > 0)
		{
			ft_putchar(' ');
			prec = 1;
		}
	}
	if ((lenmod->blen > 0 || lenmod->alen > 0) && !lenmod->minus && !lenmod->zero)
	{
		if (lenmod->space == 1)
			pr2 = cheese(varg, lenmod, (num * 10), NULL);
		else
			pr2 = cheese(varg, lenmod, num, NULL);
	}
	if (lenmod->plus == 1)
	{
		i = 0;
		if (num > 0)
		{
			ft_putchar('+');
			if (lenmod->zero == 1)
			{
				i = 0;
				while (i < lenmod->blen - ft_intlen(num) - 1)
				{
					ft_putchar('0');
					i++;
				}
			}
			ft_putstr(ft_itoa_base(num, 10));
			return (ft_intlen(num) + 1 + i);
		}
	}
	if (lenmod->zero == 1)
	{
		i = 0;
		if (lenmod->alen)
		{
			if (lenmod->blen > lenmod->alen)
			{
				prec = lenmod->alen;
				while (prec < lenmod->blen)
				{
					ft_putchar(' ');
					prec++;
					i++;
				}
			}
			prec = 0;
			while (prec < (lenmod->alen - ft_intlen(num)))
			{
				ft_putnbr(0);
				prec++;
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < (lenmod->blen - ft_intlen(num)))
			{
				ft_putchar('0');
				i++;
			}
		}
		ft_lontint2(num);
		return (i + ft_intlen(num));
	}
	ft_lontint2(num);
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);
		j = i;
		while (i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (lenmod->zero)
		return (i + ft_intlen(num));
	else if (lenmod->blen || lenmod->alen)
	{
		if (lenmod->space == 1)
			return (ft_intlen(num * 10) + pr2 + 1);
		return (ft_intlen(num) + pr2 + (lenmod->space ? 1 : 0));
	}
	return (prec + ft_intlen(num) + (i - j) + ((lenmod->blen > lenmod->alen) ? lenmod->blen - lenmod->alen : 0) - pr2);
}
