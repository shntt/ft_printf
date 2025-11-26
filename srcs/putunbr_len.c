/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/26 23:39:08 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunbr_len(unsigned int n)
{
	char	digit;
	int		len;
	int		tmp;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 10)
	{
		tmp = putunbr_len(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	digit = (char)(n % 10 + '0');
	if (write(1, &digit, 1) == -1)
		return (-1);
	len++;
	return (len);
}
