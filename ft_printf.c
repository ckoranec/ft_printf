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

int cheese(t_varg *varg,t_lenmod *lenmod,intmax_t brie,char *chedder)
{
	int swiss;
	int gouda;
	int munster;
	int blue;
	swiss = 0;
	gouda = 0;
	munster = 0;
	blue = 0;
if(varg->d == 1||varg->i == 1||varg->u == 1)
	{
		swiss = ft_intlen(brie);	
	}
else if(varg->c == 1)
	{
		swiss = 1;
	}
else if (varg->p ==1)
	{
		if (brie == 0)
			{
				swiss = 3;
			}
		else
			swiss = ft_strlen(chedder + 2);
	}
else
	swiss = ft_strlen(chedder);
	munster = lenmod->alen - swiss;
if(munster < 0)
	munster = 0;
while(swiss < (lenmod->blen - munster))
	{
		ft_putchar(' ');
		swiss++;
	}
while (gouda < munster)
	{
		ft_putchar('0');
		gouda++;
		swiss++;
	}
	return(swiss);
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
while(str)
write(1,&str[i++],1);
return(i);
}

int print_s(t_varg *varg,t_lenmod *lenmod, va_list ap)
{
	char *str;
	int i;
	wchar_t *ptr;
	str = va_arg(ap, char *);
	i = ft_strlen(str);

		if(lenmod->blen < 0 || lenmod->alen <0)
		{		
		cheese(varg,lenmod,0,str);
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
	num = 0;
	i = 0;
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
				num = (int)va_arg(ap, int);
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
if(varg->bigo == 1 || varg->bigx == 1)
{
	if (varg->bigo == 1)
		base = 8;
	else
		base = 16;
ft_putstr(supper(ft_itoa_base(num,base)));
}
else
ft_putstr(ft_itoa_base(num, base));
		if (lenmod->minus == 1)
		{
			i = ft_intlen(num);
				
		while(i < lenmod->minusnumber)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return(ft_strlen(ft_itoa_base(num,base)));
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
if(bacon == 0)
{
	ft_putchar(0);
	return(1);
}
else
ft_putstr(ft_itoa_base(bacon, 16));
return(ft_strlen(ft_itoa_base(bacon, 16)));
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
				num = (unsigned char)va_arg(ap, int);
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
		}ft_lontint2(num);
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

int print_bigd(va_list ap)
{
	long long num;
	num = va_arg(ap, long long);
	ft_longint(num);
	return(ft_intlen(num));
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
		if(lenmod->blen < 0 || lenmod->alen <0)
		{		
		cheese(varg,lenmod,num,NULL);
		}
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
ft_lontint2(num);
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
        return(print_s(varg,lenmod,ap));
    }
    else if(varg->d == 1)
    {
        print_d_i(varg,lenmod,ap);
    }
    else if(varg->c == 1 || varg->bigc == 1)
    {
        return (print_c(varg,lenmod,ap));
    }
	else if(varg->o == 1 || varg->x == 1 || varg->bigx == 1 || varg->bigo == 1)
	{
	print_o_x(varg,lenmod, ap);
	}
	else if(varg->u == 1)
	{
	print_u(varg, lenmod, ap);
	}
	if(varg->bigs == 1 || (varg->s && lenmod->l == 1))
	{
		print_bigs(ap);
	}
	if(varg->bigd == 1)
	{
		print_bigd(ap);
	}
    return(1);
}

int parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s)
{
	int i;
		char *str;
	int j;
	int strpos;
	int len;

	len = 0;
	str = ft_memalloc(40);
	i = 0;
	j = 0;
	strpos = 0;
	while(s[i])
	{
		strpos = 0;
		j = 0;
		if(varg->check == 1)
		{
			if (s[i] == '#')
				lenmod->pound = 1;
			if(s[i] == '%')
			{
				varg->percent = 1;
				varg->check = 0;
				ft_putchar('%');
			}
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
			if (s[i] == 'o')//done
			{
                varg->check =0;
				varg->o = 1;
			}
			if (s[i] == 'O')
			{
				varg->check = 0;
				varg->bigo = 1;
			}
			else if (s[i] == 'u')
			{
                varg->check =0;
				varg->u = 1;
			}
			if (s[i] == 'x')//done
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
			if ((ft_isdigit(s[i]) && s[i] != '0' && s[i] != '-') || s[i] == '.')
			{
				j = i + 1;
				while(ft_isdigit(s[j]))
				{
					str[strpos++] = s[j];
					j++;
				}
				lenmod->blen = ft_atoi(str);
				if(s[i] == '.')
				{
					strpos = 0;
					j = i + 1;
					while(ft_isdigit(s[j]))
					{
						str[strpos++] = s[j];
						j++;
					}
				lenmod->alen = ft_atoi(str);
				}
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
			if(s[i] == 'l')
				lenmod->l = 1;
			if (s[i] == 'h' && s[i+1] == 'h')
				lenmod->hh = 1;
			if(s[i] == 'h')
				lenmod->h = 1;
			if(s[i] == 'j')
				lenmod->j = 1;
			if(s[i] == 'z')
				lenmod->z = 1;
		}
		else if (varg->check == 0)
		{
			len += doer(varg, lenmod,ap);
			varg->check = 3;
		}
		if(s[i] == '%')
		{
			varg->check = 1;
		}
		else if(varg->check == 3)
		{
			len++;
		ft_putchar(s[i]);
		}
		i++;
	}
	return(len);
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
//	printf("theirs: %d",printf("%c\n", 42));
//	printf("mine: %d",ft_printf("%c\n", 42));
//	printf("theurs: %d\n", printf("Kashim a %c histoires à raconter\n", 1001));
//	printf("m: %d\n", ft_printf("Kashim a %c histoires à raconter\n", 1001));
//	printf("theirs %d\n", printf("Il fait au moins %c\n", -8000));
//	printf("mine %d\n", ft_printf("Il fait au moins %c\n", -8000));
//	printf("theuirs %d\n",printf("%c\n", -0));
//	printf("mine %d\n",ft_printf("%c\n", -0));
	printf("theirs %d\n", printf("%c", 0));
	printf("mine %d\n", ft_printf("%c", 0));
/*	printf("%c\n", INT_MAX);
	printf("%c\n", 'c');
	printf("%c\n", '\n');
	printf("%c", 'l');
	printf("%c", 'y');
	printf("%c", ' ');
	printf("%c", 'e');
	printf("%c", 's');
	printf("%c", 't');
	printf("%c", ' ');
	printf("%c", 'f');
	printf("%c", 'a');
	printf("%c", 'n');
	printf("%c", 't');
	printf("%c", 'a');
	printf("%c", 's');
	printf("%c", 't');
	printf("%c", 'i');
	printf("%c", 'q');
	printf("%c", 'u');
	printf("%c", 'e');
	printf("%c\n", '!');
	printf("%c\n", '\r');
	printf("%c\n", '\t');

 	ft_printf("hello there %c\n frued\n",'a');
 	printf("%O", 200);
 	return(0);
 }*/