/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/26 23:16:37 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_positive(long long lln, int len)
{
	int		tmp;
	char	digit;

	if (lln >= 10)
	{
		tmp = putnbr_len(lln / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	digit = (char)(lln % 10 + '0');
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (len + 1);
}

int	putnbr_len(int n)
{
	long long	lln;
	int			len;

	lln = (long long)n;
	if (lln == 0)
		return (write(1, "0", 1));
	len = 0;
	if (lln < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		lln *= -1;
		len = 1;
	}
	return (write_positive(lln, len));
}
