/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:49:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/09 11:22:14 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
int check_string(char char_tocheck, va_list list_arg)
{
	char *base;
	base = "0123456789abcdef";
	if (char_tocheck == '%')
		return (ft_putchar('%'));
	else if (char_tocheck == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
	else if (char_tocheck == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	else if (char_tocheck == 'p')
	{
		int retprefix = ft_putstr("0x");
		return (retprefix + ft_addresstohex(va_arg(list_arg, unsigned long), base));
	}
	else if (char_tocheck == 'd')
		return (ft_putstr(va_arg(list_arg, char *)));
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
	int number1;
	int number2;
	int number3;
	int number4;
	printf("enter number1 value in octal (%%i): ");
	scanf("%i", &number1);
	printf("enter number2 value in hexadecimal (%%i): ");
	scanf("%i", &number2);
	printf("enter number3 value: in octal (%%d): ");
	scanf("%d", &number3);
	printf("enter number4 value: in hexadecimal (%%d): ");
	scanf("%d", &number4);
	printf("value of number1(octal) converted to decimal %i:\n ", number1);
	printf("value of number2(hexadecimal) converted to decimal %i:\n ", number2);
	printf("value of number3(octal) in decimal %d:\n ", number3);
	printf("value of number4(hexadecimal) in decimal %d:\n ", number4);
}
