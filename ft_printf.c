/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:47:27 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/12 17:49:24 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>



int putwstr(wchar_t *str)
{
int i;
i = 0;
while(str)
write(1,&str[i++],1);
return(i);
}

int print_s(t_lenmod *lenmod, va_list ap)
{
	char *str;
	int i;
	wchar_t *ptr;
	str = va_arg(ap, char *);
	i = ft_strlen(str);

	if(lenmod->minus == 1)
	{
		if(lenmod->minusnumber <= i)
		{
			ft_putstr(str);
			return (i);
		}
		else if (lenmod->minusnumber >= i)
		 {
			 ft_putstr(str);
			 while(i < lenmod->minusnumber)
			 {
				 ft_putchar(' ');
				 i++;
			 }
			 return(i + ft_strlen(str));
		 }
	}
	else if(lenmod->l == 1)
	{
		ptr = va_arg(ap, wchar_t *);
		return(putwstr(ptr));
	}
	else
	ft_putstr(str);
		return(ft_strlen(str));
}

int	print_c(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	wchar_t fatc;
	char c;
int i;
i = 1;
if(varg->bigc == 1)
{
	fatc = va_arg(ap, wchar_t);
	ft_putchar(fatc);
}
	c = va_arg(ap, int);
	
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
/*			if (lenmod->zero == 1)
		{
			while(i < lenmod->zeronumber)
			{
				ft_putnbr(0);
				i++;
			}
		}
			else if(lenmod->l == 1)
	{
		c = va_arg(ap, wint_t);
		return(putwchar(c));
	}*/
		else
		ft_putchar(c);
		return(1);
}

int print_p(va_list ap)
{
unsigned long long bacon;

bacon = va_arg(ap, long long);
if(bacon == 0)
{
	ft_putchar(0);
	return(1);
}
else
ft_putstr(ft_itoa_base(bacon, 16));
return(ft_strlen(ft_itoa_base(bacon, 16)));
}

int print_d_i(t_lenmod *lenmod,va_list ap)
{
	int i;
	intmax_t num;
	num = 0;
	i = 0;
	
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
		if(lenmod->plus == 1)
		{
			if(num > 0)
			{
			ft_putchar('+');
			return(ft_intlen(num + 1));
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
ft_longint(num);
	if (lenmod->minus == 1)
	{
				i = ft_intlen(num);
				
		while(i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}

	return(ft_intlen(num));
}
int doer(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
    if(varg->s == 1)
    {
        print_s(lenmod,ap);
    }
    if(varg->d == 1)
    {
        print_d_i(lenmod,ap);
    }
    if(varg->c == 1)
    {
        print_c(lenmod,ap);
    }
    return(1);
}

int parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s)
{
	int i;
		char *str;
	int j;
	int strpos;
	str = ft_memalloc(40);
	i = 0;
	j = 0;
	strpos = 0;
	while(s[i])
	{
		if(varg->check == 1)
		{
			if (s[i] == '#')
				lenmod->pound = 1;
			if(s[i] == '%')
				varg->percent = 1;
			if (s[i] == 's')//done
			{
				varg->check = 0;
				varg->s = 1;
			}
			if (s[i] == 'p')//done
			{
                varg->check = 0;
				varg->p = 1;
			}
			if(s[i] == 'd')//done
			{
                varg->check = 0;
				varg->d = 1;
			}
			if( s[i] == 'i')//done
			{
                varg->check = 0;
				varg->i = 1;
			}
			if (s[i] == 'D')
			{
                varg->check =0;
				varg->bigd = 1;
			}
			if (s[i] == 'o')
			{
                varg->check =0;
				varg->o = 1;
			}
			if (s[i] == 'u')
			{
                varg->check =0;
				varg->u = 1;
			}
			if (s[i] == 'x')
			{
                varg->check =0;
				varg->x = 1;
			}
			if(s[i] == 'X')
			{
                varg->check =0;
				varg->bigx = 1;
			}
			if (s[i] == 'c')//done
			{
                varg->check =0;
				varg->c = 1;
			}
			if(s[i] == '#')
				lenmod->pound = 1;
			if(s[i] == '0')
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
			if (s[i] == '-')
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
			if (s[i] == '+')
				lenmod->plus = 1;
			if (s[i] == 'C')
			{
                varg->check =0;
				varg->bigc = 1;
			}
			if(s[i] == 'l' && s[i + 1] == 'l')
				lenmod->ll = 1;
			else if(s[i] == 'l')
				lenmod->l = 1;
			if (s[i] == 'h' && s[i+1] == 'h')
				lenmod->hh = 1;
			else if(s[i] == 'h')
				lenmod->h = 1;
			if(s[i] == 'j')
				lenmod->j = 1;
			if(s[i] == 'z')
				lenmod->z = 1;
		}
		else if(s[i] == '%')
		{
			varg->check = 1;
		}
		else if (varg->check == 0)
		{
			doer(varg, lenmod,ap);
			varg->check = 3;
//			else if(varg->d == 1)
//				print_d_i(varg,lenmod,ap);
		}
		if(varg->check == 3)
		{
		ft_putchar(s[i]);
		}
		i++;
	}
	return(0);
}

void initialize(t_lenmod *lenmod, t_varg *varg)
{
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
    varg->bigu = 0;
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
	parse(ap, &varg, &lenmod, str);
	return(0);
}
/*
int main()
{
	ft_printf("%10c\n", 'g');
	printf("%10c\n", 'g');
	return(0);
}
*/