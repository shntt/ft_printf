/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/20 21:59:38 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putunbr_len(unsigned int n)
{
	char	digit;
	int		len;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		len++;
		return (len);
	}
	if (n >= 10)
		len += putunbr_len(n / 10);
	digit = (char)(n % 10 + '0');
	write(1, &digit, 1);
	len++;
	return (len);
}
