/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 22:00:42 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/20 22:05:00 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VARG_H
# define FT_VARG_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_varg
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
}				t_varg;

typedef	struct		s_lenmod
{
	int	alen;
	int	blen;
	int	minusnumber;
	int	zeronumber;
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	j;
	int	z;
	int	pound;
	int	zero;
	int	minus;
	int	plus;
	int	space;
}					t_lenmod;

void	ft_lontint2(long long n);
int		doer(t_varg *varg, t_lenmod *lenmod, va_list ap);
int		print_s(t_varg *varg, t_lenmod *lenmod, va_list ap);
int		print_d_i(t_varg *varg, t_lenmod *lenmod, va_list ap);
int		print_c(t_varg *varg, t_lenmod *lenmod, va_list ap);
int		ft_printf(const char *str, ...);
int	cheese(t_varg *varg, t_lenmod *lenmod, intmax_t num, char *str);
int		putwstr(wchar_t *str);
char *supper(char *s);
char	*ft_ultoa_base(unsigned long long nbr, unsigned int base);
void initialize(t_lenmod *lenmod, t_varg *varg);
int	print_o_x(t_varg *varg, t_lenmod *lenmod, va_list ap);
int	print_u(t_varg *varg, t_lenmod *lenmod, va_list ap);
int	print_bigs(va_list ap);
int	print_bigd(va_list ap);
int	print_p(va_list ap);
int	parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s);
#endif
