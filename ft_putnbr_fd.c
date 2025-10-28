/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:42:33 by shitakah          #+#    #+#             */
/*   Updated: 2025/10/23 00:58:41 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		digit;
	long long	lln;

	lln = (long long)n;
	if (lln == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (lln < 0)
	{
		write(fd, "-", 1);
		lln *= -1;
	}
	if (lln >= 10)
	{
		ft_putnbr_fd(lln / 10, fd);
	}
	digit = (char)(lln % 10 + '0');
	write(fd, &digit, 1);
}
