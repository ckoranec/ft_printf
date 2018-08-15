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
	int bigs;
	int bigd;
	int i;
	int o;
	int p;
	int bigo;
	int u;
	int bigu;
	int x;
	int bigx;
	int bigc;
}			t_varg;

typedef struct s_lenmod
{
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

int doer(t_varg *varg, t_lenmod *lenmod, va_list ap);
int print_s(t_lenmod *lenmod, va_list ap);
int print_d_i(t_lenmod *lenmod,va_list ap);
int	print_c(t_lenmod *lenmod, va_list ap);
#endif
