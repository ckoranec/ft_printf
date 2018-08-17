/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 21:33:50 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/12 21:33:54 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
