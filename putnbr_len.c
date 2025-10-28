/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/10/29 01:50:56 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_len(int n)
{
	char		digit;
	long long	lln;
	int			len;

	len = 0;
	lln = (long long)n;
	if (lln == 0)
	{
		write(1, "0", 1);
		len++;
		return (len);
	}
	if (lln < 0)
	{
		write(1, "-", 1);
		lln *= -1;
		len++;
	}
	if (lln >= 10)
		len += putnbr_len(lln / 10);
	digit = (char)(lln % 10 + '0');
	write(1, &digit, 1);
	len++;
	return (len);
}
