/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 23:35:02 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/05 20:42:55 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	processf(va_list *args, const char *format, int i, int count);
static int	check_type(va_list *args, const char *format, int i, int count);

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = processf(&args, format, 0, 0);
	va_end(args);
	return (count);
}

static int	check_type(va_list *args, const char *format, int i, int count)
{
	if (format[i] == 'c')
		count += putchar_len(va_arg(*args, int));
	else if (format[i] == 's')
		count += putstr_len(va_arg(*args, char *));
	else if (format[i] == 'p')
		count += putptr_len((unsigned long long)va_arg(*args, void *), 1);
	else if (format[i] == 'd' || format[i] == 'i')
		count += putnbr_len(va_arg(*args, int));
	else if (format[i] == 'u')
		count += putunbr_len(va_arg(*args, unsigned int));
	else if (format[i] == 'x')
		count += puthex_len((unsigned long long)va_arg(*args, unsigned int), 0);
	else if (format[i] == 'X')
		count += puthex_len((unsigned long long)va_arg(*args, unsigned int), 1);
	else if (format[i] == '%')
		count += putchar_len('%');
	else if (format[i] != '\0')
	{
		write(1, "%", 1);
		write(1, &(format[i]), 1);
		count += 2;
	}
	return (count);
}

static int	processf(va_list *args, const char *format, int i, int count)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += check_type(args, format, i, 0);
			if (format[i] != '\0')
				i++;
		}
		else
		{
			count += putchar_len(format[i]);
			i++;
		}
	}
	return (count);
}
