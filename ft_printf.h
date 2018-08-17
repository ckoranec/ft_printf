#ifndef FT_varg_H
# define FT_varg_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_varg
{
	int percent;
	int check;
	int c;
	int d;
	int s;
	int i;
	int o;
	int p;
	int u;
	int x;
	int bigx;
	int bigc;
	int bigs;
	int bigd;
	int bigo;
}			t_varg;

typedef struct s_lenmod
{
	int alen;
	int blen;
	int minusnumber;
	int zeronumber;
	int h;
	int hh;
	int l;
	int ll;
	int j;
	int z;
	int pound;
	int zero;
	int minus;
	int plus;
}				t_lenmod;
void	ft_lontint2(long long n);
int doer(t_varg *varg, t_lenmod *lenmod, va_list ap);
int print_s(t_lenmod *lenmod, va_list ap);
int print_d_i(t_lenmod *lenmod,va_list ap);
int	print_c(t_varg *varg,t_lenmod *lenmod, va_list ap);
#endif
