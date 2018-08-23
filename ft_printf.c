/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:47:27 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/20 21:32:59 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

char	*ft_ultoa_base(unsigned long long nbr, unsigned int base)
{
	int		length;
	unsigned long long	sign;
	char	*str;
	char	*ptr;

	ptr = "0123456789abcdef";

	sign = (unsigned long long)nbr;
	//if (nbr == -2147483648)
	//	return (str = ft_strdup("-2147483648"));
	str = ft_strnew(60);
	if (!str)
		return (NULL);
	length = 0;
	str[length++] = ptr[sign % base];
	while (sign /= base)
		str[length++] = ptr[sign % base];
	str[length] = '\0';
	ft_strrev(str);
	return (str);
}
void initialize(t_lenmod *lenmod, t_varg *varg)
{
	lenmod->alen = 0;
	lenmod->blen = 0;
	varg->percent = 0;
	varg->check = 3;
	varg->c = 0;
	varg->s = 0;
	varg->d = 0;
	varg->bigs = 0;
	varg->bigd = 0;
	varg->i = 0;
	varg->o = 0;
	varg->bigo = 0;
	varg->u = 0;
	varg->x = 0;
	varg->bigx = 0;
	varg->bigc = 0;
	lenmod->h = 0;
	lenmod->hh = 0;
	lenmod->l = 0;
	lenmod->ll = 0;
	lenmod->j = 0;
	lenmod->z = 0;
	lenmod->pound = 0;
	lenmod->zero = 0;
	lenmod->minus = 0;
	lenmod->plus = 0;
	lenmod->zeronumber = 0;
	lenmod->space = 0;
}

int cheese(t_varg *varg, t_lenmod *lenmod, intmax_t num, char *str)
{
	int len;
	int counter;
	int munster;

	len = 0;
	counter = 0;
	munster = 0;
	if(varg->d == 1||varg->i == 1||varg->u == 1)
		len = ft_intlen(num);	
	else if(varg->c == 1)
		len = 1;
	else if (varg->p == 1)
	{
		if (num == 0)
			len = 3;
		else
			len = ft_strlen(str + 2);
	}
	else
	{
		len = ft_strlen(str);
	}
	munster = lenmod->alen;
	if(munster < 0)
		munster = 0;
	while(len < (lenmod->blen - munster))
	{
		ft_putchar(' ');
		len++;
	}
	counter = 0;
	if (lenmod->space == 1)
	{
		while (counter < (lenmod->alen - ft_intlen(num / 10)) && !varg->s)
		{
			ft_putchar('0');
			counter++;
			len++;
		}
		counter--;
	}
	else
	{
		while (counter < (lenmod->alen - ft_intlen(num)) && !varg->s)
		{
			ft_putchar('0');
			counter++;
			len++;
		}
	}
	return(counter);
}

void	ft_lontint2(long long n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_lontint2(-n);
	}
	else if (n > 9)
	{
		ft_lontint2(n / 10);
		ft_lontint2(n % 10);
	}
	else
		ft_putchar(n + '0');
}


int putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return(i);
}

int print_s(t_varg *varg,t_lenmod *lenmod, va_list ap)
{
	char *str;
	int i;
	wchar_t *ptr;
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
	if(lenmod->blen || lenmod->alen)
	{		
		prec = cheese(varg,lenmod,0,str);
	}

	if(lenmod->minus == 1)
	{
		if(lenmod->minusnumber <= i)
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
			while(prec < lenmod->minusnumber)
			{
				ft_putchar(' ');
				prec++;
			}
			//		printf("i: %d\n", i);
			//		printf("precL %d\n", prec);
			return((lenmod->blen));
		}
	}
	else if(lenmod->l == 1)
	{
		ptr = va_arg(ap, wchar_t *);
		return(putwstr(ptr));
	}
	else
	{
		ft_putstr(str);
	}
	return(ft_strlen(str) + prec);
}

char *supper(char *s)
{
	int i;
	i = 0;
	while(s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return(s);
}

int print_o_x(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	int base;
	int i;
	intmax_t num;
	int	len;
	num = 0;
	i = 0;
	len = 0;

	if(varg->o == 1)
	{
		base = 8;
	}
	else if(varg->x == 1)
	{
		base = 16;
	}
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if(lenmod->l == 1)
			num = (long)va_arg(ap,intmax_t);
		else
			num = (long long)va_arg(ap, intmax_t);
	}
	else if(lenmod->h == 1)
		num = (char)va_arg(ap, int);
	else if(lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if(lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (long long)va_arg(ap, long long);

	if(lenmod->blen < 0 || lenmod->alen <0)
	{		
		cheese(varg,lenmod,0,ft_itoa_base(num,base));
	}
	if(lenmod->plus == 1)
	{
		if(num > 0)
		{
			ft_putchar('+');
			return(ft_strlen(ft_itoa_base(num + 1, base)));
		}
	}

	if (lenmod->zero == 1)
	{
		i = ft_intlen(num);
		while(i < lenmod->zeronumber)
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
	if(varg->bigo == 1 || varg->bigx == 1)
	{
		if (varg->bigo == 1)
			base = 8;
		else
			base = 16;
		ft_putstr(supper(ft_itoa_base(num,base)));
	}
	else
	{
		ft_putstr(ft_itoa_base(num, base));
	}
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);

		while(i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return(ft_strlen(ft_itoa_base(num,base)) + len);
}

int	print_c (t_varg *varg,t_lenmod *lenmod, va_list ap)
{
	wchar_t fatc;
	char c;
	int i;
	c = '\0';
	i = 1;

	if(varg->bigc == 1)
	{
		fatc = va_arg(ap, wchar_t);
		ft_putchar(fatc);
		return (1);
	}
	else
		c = va_arg(ap, int);\

			if (c == '\0')
			{
				ft_putchar('\0');
				return (1);
			}
	if(lenmod->blen > 0 || lenmod->alen > 0)
	{
		cheese(varg,lenmod,0,NULL);
	}
	if(lenmod->minus == 1)
	{
		if(lenmod->minusnumber <= i)
		{
			ft_putchar(c);
			return (1);
		}
		else if (lenmod->minusnumber >= i)
		{
			ft_putchar(c);
			while(i < lenmod->minusnumber)
			{
				ft_putchar(' ');
				i++;
			}
			return(i + 1);
		}
	}
	else
		ft_putchar(c);
	return(1);
}

int print_p(va_list ap)
{
	unsigned long long bacon;

	bacon = va_arg(ap, long long);
	ft_putchar('0');
	ft_putchar('x');
	if(bacon == 0)
	{
		ft_putchar('0');
		return(3);
	}
	else
		ft_putstr(ft_itoa_base(bacon, 16));
	return(ft_strlen(ft_itoa_base(bacon, 16)) + 2);
}

int print_u(t_varg *varg,t_lenmod *lenmod, va_list ap)
{
	int i;
	intmax_t num;
	num = 0;
	i = 0;
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if(lenmod->l == 1)
			num = (unsigned long)va_arg(ap,intmax_t);
		else
			num = (unsigned long long)va_arg(ap, intmax_t);
	}
	else if(lenmod->h == 1)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if(lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if(lenmod->z == 1)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (unsigned int)va_arg(ap, int);
	if(lenmod->blen < 0 || lenmod->alen <0)
	{		
		cheese(varg,lenmod,num,NULL);
	}
	if(lenmod->plus == 1)
	{
		if(num > 0)
		{
			ft_putchar('+');
			return(ft_strlen(ft_ultoa_base(num, 10)) + 1);
		}
	}

	if (lenmod->zero == 1)
	{
		i = ft_intlen(num);
		while(i < lenmod->zeronumber)
		{
			ft_putnbr(0);
			i++;
		}
	}
	ft_putstr(ft_ultoa_base(num, 10));
	if (lenmod->minus == 1)
	{
		i = ft_intlen(num);

		while(i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}

	return(ft_strlen(ft_ultoa_base(num, 10)));
}

int print_bigd(va_list ap)
{
	long long num;
	num = va_arg(ap, long long);
	ft_longint(num);
	return(ft_strlen(ft_itoa_base(num, 10)));
}

int print_bigs(va_list ap)
{
	int i;
	wchar_t *s;
	i = 0;
	s = va_arg(ap, wchar_t *);
	putwstr(s);
	while(s[i])
		i++;
	return(i);
}

int print_d_i(t_varg *varg,t_lenmod *lenmod,va_list ap)
{
	int i;
	intmax_t num;
	int	j;
	int	prec;
	int	pr2;

	j = 0;
	num = 0;
	i = 0;
	prec = 0;
	pr2 = 0;
	if (lenmod->l == 1 || lenmod->ll == 1)
	{
		if(lenmod->l == 1)
			num = (long)va_arg(ap,intmax_t);
		else
			num = (long long)va_arg(ap, intmax_t);
	}
	else if(lenmod->h == 1)
		num = (char)va_arg(ap, int);
	else if(lenmod->j == 1)
		num = va_arg(ap, intmax_t);
	else if(lenmod->z == 1)
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
	if((lenmod->blen > 0 || lenmod->alen >0) && !lenmod->minus && !lenmod->zero)
	{
		if (lenmod->space == 1)
			pr2 = cheese(varg,lenmod,(num * 10),NULL);
		else
			pr2 = cheese(varg,lenmod,num ,NULL);
		//pr2 = lenmod->blen - ft_intlen((num / 10));
	}
	if(lenmod->plus == 1)
	{i = 0;
		if(num > 0)
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
			return(ft_intlen(num ) + 1 + i);
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

			while(prec < (lenmod->alen - ft_intlen(num)))
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
		while(i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (lenmod->zero)
	{
		return (i + ft_intlen(num));
	}
	else if (lenmod->blen || lenmod->alen)
	{
		if (lenmod->space == 1)
		{
			return (ft_intlen(num * 10) + pr2 + 1);
		}
		return (ft_intlen(num) + pr2 + (lenmod->space ? 1: 0));
	}
	return(prec + ft_intlen(num) + (i - j) + ((lenmod->blen > lenmod->alen) ? lenmod->blen - lenmod->alen : 0) - pr2);
}
int doer(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	if(varg->s == 1 && lenmod->l == 0)
	{
		return(print_s(varg,lenmod,ap));
	}
	else if(varg->d == 1 || varg->i == 1)
	{
		return (print_d_i(varg,lenmod,ap));
	}
	else if(varg->c == 1 || varg->bigc == 1)
	{
		return (print_c(varg,lenmod,ap));
	}
	else if(varg->o == 1 || varg->x == 1 || varg->bigx == 1 || varg->bigo == 1)
	{
		return (print_o_x(varg,lenmod, ap));
	}
	else if(varg->u == 1)
	{
		return (print_u(varg, lenmod, ap));
	}
	else if(varg->bigs == 1 || (varg->s && lenmod->l == 1))
	{
		return (print_bigs(ap));
	}
	else if(varg->bigd == 1)
	{
		return (print_bigd(ap));
	}
	else if (varg->p == 1)
		return (print_p(ap));
	else
		return (1);
	//return(1);
}

int		ft_conv_check(char *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (c == s[i])
			return (1);
	return (0);
}

int parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s)
{
	int i;
	char *str;
	int j;
	int strpos;
	int len;
	int x;

	len = 0;
	str = ft_memalloc(40);
	i = 0;
	j = 0;
	strpos = 0;
	while(s[i])
	{
		if (s[i] == '*' && (ft_conv_check("sSpdDioOuUxXcC", s[i + 1]) || ft_conv_check("sSpdDioOuUxXcC", s[i + 2])))
			x = va_arg(ap, int);
		strpos = 0;
		j = 0;
		if(varg->check == 1)
		{
			if (s[i] == '#')
				lenmod->pound = 1;
			else if(s[i] == '%')
			{
				len++;
				varg->percent = 1;
				varg->check = 3;
				ft_putchar('%');
			}
			else if (s[i] == 's')//done
			{
				varg->check = 0;
				varg->s = 1;
			}
			else if (s[i] == 'p')//done
			{
				varg->check = 0;
				varg->p = 1;
			}
			else if(s[i] == 'd')//done
			{
				varg->check = 0;
				varg->d = 1;
			}
			else if( s[i] == 'i')//done
			{
				varg->check = 0;
				varg->i = 1;
			}
			else if (s[i] == 'D')
			{
				varg->check =0;
				varg->bigd = 1;
			}
			else if (s[i] == 'o')//done
			{
				varg->check =0;
				varg->o = 1;
			}
			else if (s[i] == 'O')
			{
				varg->check = 0;
				varg->bigo = 1;
			}
			else if (s[i] == 'u')
			{
				varg->check =0;
				varg->u = 1;
			}
			else if (s[i] == 'x')//done
			{
				varg->check =0;
				varg->x = 1;
			}
			else if(s[i] == 'X')
			{
				varg->check =0;
				varg->bigx = 1;
			}
			else if (s[i] == 'c')//done
			{
				varg->check =0;
				varg->c = 1;
			}
			else if(s[i] == '#')
				lenmod->pound = 1;
			else if (s[i] == ' ')
			{
				lenmod->space = 1;
			}
			else if(s[i] == '0')
			{

				lenmod->zero = 1;
				ft_bzero(&*str,ft_strlen(str));
				j = i + 1;
				while(ft_isdigit(s[j]))
				{
					str[strpos++] = s[j];
					j++;
				}
				lenmod->zeronumber = ft_atoi(str);
			}
			else if (s[i] == '-')
			{
				lenmod->minus = 1;
				j = i + 1;
				while(ft_isdigit(s[j]))
				{
					str[strpos++] = s[j];
					j++;
				}
				lenmod->minusnumber = ft_atoi(str);
			}
			else if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.')
			{
				j = i;
				strpos = 0;
				while(ft_isdigit(s[j]))
				{
					str[strpos++] = s[j];
					j++;
				}
				lenmod->blen = ft_atoi(str);
				if(s[j] == '.')
				{
					strpos = 0;
					j++;
					while(ft_isdigit(s[j]))
					{
						str[strpos++] = s[j];
						j++;
					}
					lenmod->alen = ft_atoi(str);
					i = j - 1;
				}
			}
			else if (s[i] == '+')
				lenmod->plus = 1;
			else if (s[i] == 'C')
			{
				varg->check =0;
				varg->bigc = 1;
			}
			else if(s[i] == 'l' && s[i + 1] == 'l')
				lenmod->ll = 1;
			else if(s[i] == 'l')
			{
				lenmod->l = 1;
			}
			else if (s[i] == 'h' && s[i+1] == 'h')
				lenmod->hh = 1;
			else if(s[i] == 'h')
				lenmod->h = 1;
			else if(s[i] == 'j')
				lenmod->j = 1;
			else if(s[i] == 'z')
				lenmod->z = 1;
			else if (s[i] == ' ' && lenmod->space != 1)
			{
				// make sure to account for adding this one space when your return the byte count
				ft_putstr(" ");
				lenmod->space = 1;
			}
		}

		else if(s[i] == '%')
		{
			varg->check = 1;
		}
		else if(varg->check == 3)
		{
			len++;
			ft_putchar(s[i]);
		}
		if (varg->check == 0)
		{

			len += doer(varg, lenmod,ap);
			varg->check = 3;
			initialize(lenmod, varg);
		}
		i++;
	}
	return(len);
}



int ft_printf(const char *str, ...)
{
	va_list ap;
	//    int w;
	//    int len;
	t_varg varg;
	t_lenmod lenmod;
	//   w  = 0;
	va_start(ap, str);
	initialize(&lenmod, &varg);
	return (parse(ap, &varg, &lenmod, str));
	///return(0);
}/*
	int main()
	{






	printf("%d\n", ft_printf("%%+04d 42 == %0+04d\n", 42));
	printf("%d\n", printf("%%+04d 42 == %0+04d\n", 42));



	return(0);
	}*/
