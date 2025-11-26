/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:49:27 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/26 21:01:01 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_len(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (-1);
		s++;
		len++;
	}
	return (len);
}
