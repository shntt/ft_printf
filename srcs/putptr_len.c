/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:55:56 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/26 23:37:08 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_body(unsigned long long hex)
{
	int		len;
	int		tmp;
	char	*ldict;

	ldict = "0123456789abcdef";
	len = 0;
	if (hex >= 16)
	{
		tmp = putptr_len(hex / 16, 0);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &ldict[hex % 16], 1) == -1)
		return (-1);
	return (len + 1);
}

int	putptr_len(unsigned long long hex, int flag)
{
	int	len;
	int	tmp;

	if (flag == 1 && hex == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	len = 0;
	if (flag == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		len = 2;
	}
	if (hex == 0)
		return (write(1, "0", 1));
	tmp = write_body(hex);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}
