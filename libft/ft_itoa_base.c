/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:01:22 by jkertgat          #+#    #+#             */
/*   Updated: 2018/08/08 19:37:30 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long nbr, unsigned int base)
{
	int		length;
	long	sign;
	char	*str;
	char	*ptr;

	ptr = "0123456789abcdef";
	sign = (long long)nbr;
	if (nbr < 0)
		return (NULL);
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	str = ft_strnew(33);
	if (!str)
		return (NULL);
	length = 0;
	if (nbr < 0)
		str[length++] = '-';
	sign = (nbr < 0) ? -sign : sign;
	str[length++] = ptr[sign % base];
	while (sign /= base)
		str[length++] = ptr[sign % base];
	str[length] = '\0';
	ft_strrev(str);
	return (str);
}
