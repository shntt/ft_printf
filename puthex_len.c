/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/10/29 01:57:00 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex_len(unsigned long long hex, int cs)
{
	char	digit;
	int		len;
	char	*ldict;

	len = 0;
	if (cs == 0)
		ldict = "0123456789abcdef";
	if (cs == 1)
		ldict = "0123456789ABCDEF";
	if (hex == 0)
	{
		write(1, "0", 1);
		len++;
		return (len);
	}
	if (hex >= 16)
		len += puthex_len(hex / 16, cs);
	digit = ldict[hex % 16];
	write(1, &digit, 1);
	len++;
	return (len);
}
