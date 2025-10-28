/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/10/28 20:57:17 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	putstr_len_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (*s)
	{
		write(fd, s++, 1);
		len++;
	}
	return (len);
}

int	putnbr_len_fd(int n, int fd)
{
	char		digit;
	long long	lln;
	int			len;

	len = 0;
	lln = (long long)n;
	if (lln == 0)
	{
		write(fd, "0", 1);
		len++;
		return (len);
	}
	if (lln < 0)
	{
		write(fd, "-", 1);
		lln *= -1;
		len++;
	}
	if (lln >= 10)
	{
		putnbr_len_fd(lln / 10, fd);
		len++;
	}
	digit = (char)(lln % 10 + '0');
	write(fd, &digit, 1);
	len++;
	return (len);
}

int	putunbr_len_fd(unsigned int n, int fd)
{
	char		digit;
	long long	lln;
	int			len;

	len = 0;
	lln = (long long)n;
	if (lln == 0)
	{
		write(fd, "0", 1);
		len++;
		return (len);
	}
	if (lln < 0)
	{
		write(fd, "-", 1);
		lln *= -1;
		len++;
	}
	if (lln >= 10)
	{
		putnbr_len_fd(lln / 10, fd);
		len++;
	}
	digit = (char)(lln % 10 + '0');
	write(fd, &digit, 1);
	len++;
	return (len);
}

int	putchar_len_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	puthex_len_fd(unsigned int hex, int fd, int cs)
{
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count = count + putchar_len_fd((format[i]), 1);
			if (format[i] == 's')
				count = count + putstr_len_fd(va_arg(args, char *), 1);
			if (format[i] == 'p')
				count = count + puthex_len_fd(va_arg(args, void *), 1, 1);
			if (format[i] == 'd' || format[i] == 'i')
				count = count + putnbr_len_fd(va_arg(args, int), 1);
			if (format[i] == 'u')
				count = count + putunbr_len_fd(va_arg(args, unsigned int), 1);
			if (format[i] == 'x')
				count = count + puthex_len_fd(va_arg(args, unsigned int), 1, 0);
			if (format[i] == 'X')
				count = count + puthex_len_fd(va_arg(args, unsigned int), 1, 1);
			if (format[i] == '%')
				count = count + putchar_len_fd('%', 1);
		}
		else
		{
			putchar_len_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	count;
	int	native_count;

	count = ft_printf("hello, %s\n", "apple");
	ft_printf("count: %d\n", count);
	native_count = printf("hello, %s\n", "apple");
	printf("pointer: %p\n", &native_count);
	printf("count: %d\n", native_count);
}

// unsigned intの文字数
// nil, null