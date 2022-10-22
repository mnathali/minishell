/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:22:22 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/26 00:22:22 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	put_address(unsigned long n)
{
	int	printed;

	printed = 0;
	printed += ft_putstr_fd("0x", 1);
	printed += ft_putnbr_base(n, "0123456789abcdef");
	return (printed);
}

int	print_flag(char flag, va_list arg)
{
	int		printed;

	printed = 0;
	if (flag == '%')
		printed += ft_putchar_fd('%', 1);
	else if (flag == 'c')
		printed += ft_putchar_fd(va_arg(arg, int), 1);
	else if (flag == 's')
		printed += ft_putstr_fd(va_arg(arg, char *), 1);
	else if (flag == 'd' || flag == 'i')
		printed += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (flag == 'u')
		printed += ft_putunbr_fd(va_arg(arg, unsigned int), 1);
	else if (flag == 'p')
		printed += put_address(va_arg(arg, unsigned long));
	else if (flag == 'x')
		printed += ft_putnbr_base(va_arg(arg, unsigned int),
				"0123456789abcdef");
	else if (flag == 'X')
		printed += ft_putnbr_base(va_arg(arg, unsigned int),
				"0123456789ABCDEF");
	return (printed);
}

int	parse_format(char const *current, va_list arg)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (current[i])
	{
		if (current[i] != '%')
			length += ft_putchar_fd(current[i++], 1);
		else if (current[i] == '%')
		{
			i++;
			length += print_flag(current[i++], arg);
		}
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list			arg;
	int				length;

	va_start(arg, format);
	length = parse_format(format, arg);
	va_end(arg);
	return (length);
}
