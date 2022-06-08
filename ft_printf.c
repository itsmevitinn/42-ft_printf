/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:49:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/08 18:16:20 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
int check_string(char char_tocheck, va_list list_arg)
{
	char *base;
	base = "0123456789abcdef";
	if (char_tocheck == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	else if (char_tocheck == 'p')
	{
		int retprefix = ft_putstr("0x");
		return (retprefix + ft_addresstohex(va_arg(list_arg, unsigned long), base));
	}
	// else if (char_tocheck == )
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
			// i++;
		}
		i++;
	}
	va_end(list_arg);
	return (printf_return);
}

#include <stdio.h>
int main(void)
{
	char *nome = "rato";
	int ret_orig = printf("printf orig: %p\n", &nome);
	printf("retorno original: %i\n", ret_orig);
	int ret_fake = ft_printf("printf fake: %p\n", &nome);
	printf("retorno fake: %i", ret_fake);
}
