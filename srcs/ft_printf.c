/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/26 22:39:33 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	processf(va_list *args, const char *format, int i, int count);
static int	check_type(va_list *args, const char *format, int i, int count);
static int	write_other_char(const char *format, int i);

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = processf(&args, format, 0, 0);
	va_end(args);
	if (count == -1)
		return (-1);
	return (count);
}

static int	write_other_char(const char *format, int i)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	if (write(1, &(format[i]), 1) == -1)
		return (-1);
	return (2);
}

static int	check_type(va_list *args, const char *format, int i, int count)
{
	int	tmp;

	tmp = 0;
	if (format[i] == 'c')
		tmp = putchar_len(va_arg(*args, int));
	else if (format[i] == 's')
		tmp = putstr_len(va_arg(*args, char *));
	else if (format[i] == 'p')
		tmp = putptr_len((unsigned long long)va_arg(*args, void *), 1);
	else if (format[i] == 'd' || format[i] == 'i')
		tmp = putnbr_len(va_arg(*args, int));
	else if (format[i] == 'u')
		tmp = putunbr_len(va_arg(*args, unsigned int));
	else if (format[i] == 'x')
		tmp = puthex_len((unsigned long long)va_arg(*args, unsigned int), 0);
	else if (format[i] == 'X')
		tmp = puthex_len((unsigned long long)va_arg(*args, unsigned int), 1);
	else if (format[i] == '%')
		tmp = putchar_len('%');
	else if (format[i] != '\0')
		tmp = write_other_char(format, i);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

static int	processf(va_list *args, const char *format, int i, int count)
{
	int	tmp;

	tmp = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmp = check_type(args, format, i, 0);
			if (tmp == -1)
				return (-1);
			count += tmp;
			if (format[i] != '\0')
				i++;
		}
		else
		{
			tmp = putchar_len(format[i]);
			if (tmp == -1)
				return (-1);
			count += tmp;
			i++;
		}
	}
	return (count);
}
