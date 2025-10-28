/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/10/28 22:40:44 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	putp_len(unsigned long long hex, int flag)
{
	char				digit;
	int					len;
	char				*ldict;

	if (flag == 1)
	{
		write(1, "0x", 2);
		flag = 0;
	}
	len = 0;
	ldict = "0123456789abcdef";
	if (hex == 0)
	{
		write(1, "0", 1);
		len++;
		return (len);
	}
	if (hex < 0)
	{
		write(1, "-", 1);
		hex *= -1;
		len++;
	}
	if (hex >= 16)
	{
		putp_len(hex / 16, 0);
		len++;
	}
	digit = ldict[hex % 16];
	write(1, &digit, 1);
	len++;
	return (len);
}

int	puthex_len(unsigned long long hex, int flag, int cs)
{
	char				digit;
	int					len;
	char				*ldict;

	if (flag == 1)
	{
		if (cs == 0)
			write(1, "0x", 2);
		if (cs == 1)
			write(1, "0X", 2);
		flag = 0;
	}
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
	if (hex < 0)
	{
		write(1, "-", 1);
		hex *= -1;
		len++;
	}
	if (hex >= 16)
	{
		puthex_len(hex / 16, 0, cs);
		len++;
	}
	digit = ldict[hex % 16];
	write(1, &digit, 1);
	len++;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
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
				count = count + putp_len((unsigned long long)va_arg(args, void *), 1);
			if (format[i] == 'd' || format[i] == 'i')
				count = count + putnbr_len_fd(va_arg(args, int), 1);
			if (format[i] == 'u')
				count = count + putunbr_len_fd(va_arg(args, unsigned int), 1);
			if (format[i] == 'x')
				count = count + puthex_len((unsigned long long)va_arg(args, unsigned int), 1, 0);
			if (format[i] == 'X')
				count = count + puthex_len((unsigned long long)va_arg(args, unsigned int), 1, 1);
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

//int	main(void)
//{
//	int	count;
//	int	native_count;

//	count = ft_printf("hello, %s\n", "apple");
//	ft_printf("count: %u\n", &count);
//	ft_printf("count: %x\n", 100);
//	native_count = printf("hello, %s\n", "apple");
//	printf("pointer: %p\n", &count);
//	printf("pointer: %lld\n", (long long)&count);
//	printf("pointer: %p\n", &native_count);
//	ft_printf("count: %x\n", &count);
//	ft_printf("count: %x\n", &native_count);
//	ft_printf("count: %p\n", 140731162493212);
//	ft_printf("count: %p\n", &native_count);
//	printf("count: %d\n", native_count);
//}
// unsigned intの文字数
// nil, null