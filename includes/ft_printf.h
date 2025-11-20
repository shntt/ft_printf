/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 00:14:27 by shitakah          #+#    #+#             */
/*   Updated: 2025/11/20 22:00:54 by shitakah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	putchar_len(char c);
int	puthex_len(unsigned long long hex, int cs);
int	putnbr_len(int n);
int	putptr_len(unsigned long long hex, int flag);
int	putstr_len(char *s);
int	putunbr_len(unsigned int n);

#endif
