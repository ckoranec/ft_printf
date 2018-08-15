/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:49:59 by jkertgat          #+#    #+#             */
/*   Updated: 2018/05/29 22:59:54 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_intlen(int n)
{
	int i;

	i = (n <= 0) ? 1 : 0;
	if(n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
