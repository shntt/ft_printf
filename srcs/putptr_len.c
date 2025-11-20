/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:55:56 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/20 21:59:32 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr_len(unsigned long long hex, int flag)
{
	char	digit;
	int		len;
	char	*ldict;

	len = 0;
	if (flag == 1 && hex == 0)
		return (write(1, "(nil)", 5), 5);
	if (flag == 1)
	{
		write(1, "0x", 2);
		len = 2;
		flag = 0;
	}
	ldict = "0123456789abcdef";
	if (hex == 0)
		return (write(1, "0", 1), ++len);
	if (hex >= 16)
		len += putptr_len(hex / 16, 0);
	digit = ldict[hex % 16];
	return (write(1, &digit, 1), ++len);
}
