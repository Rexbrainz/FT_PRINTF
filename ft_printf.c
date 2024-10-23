/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:28:58 by sudaniel          #+#    #+#             */
/*   Updated: 2024/10/23 07:20:47 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	is_c(unsigned char c, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			count++;
			continue ;
		}
		if (*format == '%')
		{
			count += is_c(*++format, ap);
			if (count == -1)
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}

static int	is_c(unsigned char c, va_list ap)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = print_char(va_arg(ap, int));
	else if (c == 'd' || c == 'i')
		result = print_int(va_arg(ap, int));
	else if (c == 's')
		result = print_string(va_arg(ap, char *));
	else if (c == 'u')
		result = print_unsigned_int(va_arg(ap, unsigned int));
	else if (c == 'p')
		result = print_pointer(va_arg(ap, void *));
	else if (c == 'x')
		result = print_hexl(va_arg(ap, unsigned int));
	else if (c == 'X')
		result = print_hexu(va_arg(ap, unsigned int));
	else if (c == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		result = 1;
	}
	return (result);
}
/*
int main(void)
{
	char *c = "Hello Rex";
	int count;	
	count = ft_printf("Scene 1, Act 1: %s, %s, %c, %d, %p\n", c, NULL,'a', 42, c);
	ft_printf("%i\n", count);
	return (0);
}
*/
