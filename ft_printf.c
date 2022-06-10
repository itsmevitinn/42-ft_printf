/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:49:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/10 16:55:18 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_string(char char_tocheck, va_list list_arg)
{
	if (char_tocheck == '%')
		return (ft_putchar('%'));
	else if (char_tocheck == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
	else if (char_tocheck == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	else if (char_tocheck == 'p')
		return (ft_putstr("0x") + size_and_print_address(list_arg, "0123456789abcdef"));
	else if (char_tocheck == 'd' || char_tocheck == 'i')
		return (size_and_print_int(list_arg));	
	else if (char_tocheck == 'u')
		return (size_and_print_unsigned(list_arg));
	else if (char_tocheck == 'x')
		return (size_and_print_hex(list_arg, "0123456789abcdef"));
	else if (char_tocheck == 'X')
		return (size_and_print_hex(list_arg, "0123456789ABCDEF"));
	return (0);
}
	
int	ft_printf(const char *string, ...)
{
	int printf_return;
	int i;
	i = 0;
	printf_return = 0;
	va_list list_arg;
	va_start (list_arg, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			printf_return += check_string(string[i + 1], list_arg);
			i++;
		}
		else
		{
			printf_return += ft_putchar(string[i]);
		}
		i++;
	}
	va_end(list_arg);
	return (printf_return);
}
#include <stdio.h>
int main(void)
{
	char *oi = "salve";
	int ret = printf("%p", &oi);
	printf("%i", ret);
}
