/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:32:17 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/21 21:06:59 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void parse3(const char *s, t_varg *varg, int i)
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
	else if (s[i] == 'O')
	{
		varg->check = 0;
		varg->bigo = 1;
	}
	else if (s[i] == 'c')
	{
		varg->check = 0;
		varg->c = 1;
	}
}

int parse2(const char *s, t_lenmod *lenmod, t_varg *varg, int i)
{
	int len;

	len = 0;
	if (s[i] == '#')
		lenmod->pound = 1;
	else if (s[i] == '%')
	{
		len++;
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
	return(len);
}

int	parse(va_list ap, t_varg *varg, t_lenmod *lenmod, const char *s)
{
	int		i;
	char	*str;
	int		j;
	int		strpos;
	int		len;

	len = 0;
	str = ft_memalloc(40);
	i = 0;
	j = 0;
	strpos = 0;
	while (s[i])
	{
		strpos = 0;
		j = 0;
		if (varg->check == 1)
		{
			len = parse2(s, lenmod, varg, i);
			parse3(s, varg, i);
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
			else if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.')
			{
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
			else if (s[i] == '+')
				lenmod->plus = 1;
			else if (s[i] == 'C')
			{
				varg->check = 0;
				varg->bigc = 1;
			}
			else if (s[i] == 'l' && s[i + 1] == 'l')
				lenmod->ll = 1;
			else if (s[i] == 'l')
			{
				lenmod->l = 1;
			}
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
		else if (s[i] == '%')
			varg->check = 1;
		else if (varg->check == 3)
		{
			len++;
			ft_putchar(s[i]);
		}
		if (varg->check == 0)
		{
			len += doer(varg, lenmod, ap);
			varg->check = 3;
			initialize(lenmod, varg);
		}
		i++;
	}
	return (len);
}
