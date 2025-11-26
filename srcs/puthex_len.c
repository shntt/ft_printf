/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/26 23:38:30 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hex(unsigned long long hex, int cs)
{
	char	*ldict;
	char	digit;
	int		len;
	int		tmp;

	if (cs)
		ldict = "0123456789ABCDEF";
	else
		ldict = "0123456789abcdef";
	len = 0;
	if (hex >= 16)
	{
		tmp = puthex_len(hex / 16, cs);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	digit = ldict[hex % 16];
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (len + 1);
}

int	puthex_len(unsigned long long hex, int cs)
{
	if (hex == 0)
		return (write(1, "0", 1));
	return (write_hex(hex, cs));
}
