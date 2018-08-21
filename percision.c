/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:29:52 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/20 21:29:54 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cheese(t_varg *varg, t_lenmod *lenmod, intmax_t num, char *str)
{
	int len;
	int counter;
	int munster;

	len = 0;
	counter = 0;
	munster = 0;
	if (varg->d == 1 || varg->i == 1 || varg->u == 1)
		len = ft_intlen(num);
	else if (varg->c == 1)
		len = 1;
	else if (varg->p == 1)
	{
		if (num == 0)
			len = 3;
		else
			len = ft_strlen(str + 2);
	}
	else
		len = ft_strlen(str);
	munster = lenmod->alen;
	if (munster < 0)
		munster = 0;
	while (len < (lenmod->blen - munster))
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
	return (counter);
}
