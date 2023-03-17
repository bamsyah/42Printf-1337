/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <bamsyah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:26:36 by bamsyah           #+#    #+#             */
/*   Updated: 2023/03/16 14:04:49 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char c, va_list args, int *len)
{
	if (c == '%')
		*len += ft_putchar_len('%');
	else if (c == 's')
		*len += ft_putstr_len(va_arg(args, char *));
	else if (c == 'c')
		*len += ft_putchar_len(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr_len(va_arg(args, int), len);
	else if (c == 'u')
		ft_putunbr_len(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_putbase(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putbase(va_arg(args, unsigned int), "0123456789ABCDEF", len);
	else if (c == 'p')
	{
		*len += ft_putstr_len("0x");
		ft_putadress(va_arg(args, unsigned long long), len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i++])
	{
		if (str[i] == '%')
			i++;
			ft_printstr(s[i], args, &len);
		else
			len += ft_putchar_len(str[i]);
	}
	va_end(args);
	return (len);
}