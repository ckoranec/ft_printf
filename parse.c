/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:32:17 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/23 22:18:48 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse3b(const char *s, t_varg *varg, int i)
{
	if (s[i] == 'O')
	{
		varg->check = 0;
		varg->bigo = 1;
	}
	else if (s[i] == 'c')
	{
		varg->check = 0;
		varg->c = 1;
	}
	else if (s[i] == 'u')
	{
		varg->check = 0;
		varg->u = 1;
	}
	else if (s[i] == 'x')
	{
		varg->check = 0;
		varg->x = 1;
	}
}

void	parse3(const char *s, t_varg *varg, int i)
{
	if (s[i] == 'i')
	{
		varg->check = 0;
		varg->i = 1;
	}
	else if (s[i] == 'D')
	{
		varg->check = 0;
		varg->bigd = 1;
	}
	else if (s[i] == 'o')
	{
		varg->check = 0;
		varg->o = 1;
	}
	else if (s[i] == 'X')
	{
		varg->check = 0;
		varg->bigx = 1;
	}
	parse3b(s, varg, i);
}

int		parse2(const char *s, t_lenmod *lenmod, t_varg *varg, int i)
{
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == '%')
	{
		lenmod->len++;
		varg->percent = 1;
		varg->check = 3;
		ft_putchar('%');
	}
	else if (s[i] == 's')
	{
		varg->check = 0;
		varg->s = 1;
	}
	else if (s[i] == 'p')
	{
		varg->check = 0;
		varg->p = 1;
	}
	else if (s[i] == 'd')
	{
		varg->check = 0;
		varg->d = 1;
	}
	return (lenmod->len);
}

void	parse4(t_lenmod *lenmod, const char *s, int strpos, int i)
{
	char	*str;
	int		j;

	str = ft_memalloc(40);
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == ' ')
	{
		lenmod->space = 1;
	}
	else if (s[i] == '0')
	{
		lenmod->zero = 1;
		ft_bzero(&*str, ft_strlen(str));
		j = i + 1;
		while (ft_isdigit(s[j]))
		{
			str[strpos++] = s[j];
			j++;
		}
		lenmod->zeronumber = ft_atoi(str);
	}
}

void	parse5_2(t_lenmod *lenmod, int i, const char *s, int strpos)
{
	char	*str;
	int		j;

	str = ft_memalloc(40);
	lenmod->zero = 1;
	ft_bzero(&*str, ft_strlen(str));
	j = i + 1;
	while (ft_isdigit(s[j]))
	{
		str[strpos++] = s[j];
		j++;
	}
	lenmod->zeronumber = ft_atoi(str);
}

void	parse5(const char *s, t_lenmod *lenmod, int strpos, int i)
{
	int		j;
	char	*str;

	str = ft_memalloc(40);
	if (s[i] == '0')
	{
		parse5_2(lenmod, i, s, strpos);
	}
	else if (s[i] == '-')
	{
		lenmod->minus = 1;
		j = i + 1;
		while (ft_isdigit(s[j]))
		{
			str[strpos++] = s[j];
			j++;
		}
		lenmod->minusnumber = ft_atoi(str);
	}
}

void	parse6(t_lenmod *lenmod, t_varg *varg, const char *s, int i)
{
	if (s[i] == '+')
		lenmod->plus = 1;
	else if (s[i] == 'C')
	{
		varg->check = 0;
		varg->bigc = 1;
	}
	else if (s[i] == 'l' && s[i + 1] == 'l')
		lenmod->ll = 1;
	else if (s[i] == 'l')
		lenmod->l = 1;
	else if (s[i] == 'h' && s[i + 1] == 'h')
		lenmod->hh = 1;
	else if (s[i] == 'h')
		lenmod->h = 1;
	else if (s[i] == 'j')
		lenmod->j = 1;
	else if (s[i] == 'z')
		lenmod->z = 1;
	else if (s[i] == ' ' && lenmod->space != 1)
	{
		ft_putstr(" ");
		lenmod->space = 1;
	}
}

void	parse7(t_lenmod *lenmod, const char *s, int i, int strpos)
{
	char	*str;
	int		j;

	str = ft_memalloc(40);
	j = i;
	strpos = 0;
	while (ft_isdigit(s[j]))
	{
		str[strpos++] = s[j];
		j++;
	}
	lenmod->blen = ft_atoi(str);
	if (s[j] == '.')
	{
		strpos = 0;
		j++;
		while (ft_isdigit(s[j]))
		{
			str[strpos++] = s[j];
			j++;
		}
		lenmod->alen = ft_atoi(str);
		i = j - 1;
	}
}

int		parse_call(t_lenmod *lenmod, const char *s, int strpos, int i)
{
	parse4(lenmod, s, strpos, i);
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == ' ')
		lenmod->space = 1;
	parse5(s, lenmod, strpos, i);
	if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.')
		parse7(lenmod, s, i, strpos);
	return (lenmod->len);
}

int		parse_check(t_varg *varg, t_lenmod *lenmod, va_list ap)
{
	if (varg->check == 0)
	{
		lenmod->len += doer(varg, lenmod, ap);
		varg->check = 3;
		initialize(lenmod, varg);
	}
	return (lenmod->len);
}

int		parse8(t_varg *varg, t_lenmod *lenmod, const char *s, int i)
{
	if (varg->check == 3)
	{
		lenmod->len++;
		ft_putchar(s[i]);
	}
	return (lenmod->len);
}

void	parse_call_2(t_lenmod *lenmod, t_varg *varg, const char *s, int i)
{
	parse6(lenmod, varg, s, i);
	parse3(s, varg, i);
	parse2(s, lenmod, varg, i);
}

int		parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s)
{
	int		i;
	int		j;
	int		strpos;

	i = 0;
	while (s[i])
	{
		strpos = 0;
		j = 0;
		if (varg->check == 1)
		{
			parse_call_2(lenmod, varg, s, i);
			parse_call(lenmod, s, strpos, i);
		}
		else if (s[i] == '%')
			varg->check = 1;
		else if (varg->check == 3)
		{
			lenmod->len++;
			ft_putchar(s[i]);
		}
		parse_check(varg, lenmod, ap);
		i++;
	}
	return (lenmod->len);
}
