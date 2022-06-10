/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:49:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/10 12:38:06 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_string(char char_tocheck, va_list list_arg)
{
	char *basehex;
	basehex = "0123456789abcdef";
	if (char_tocheck == '%')
		return (ft_putchar('%'));
	else if (char_tocheck == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
	else if (char_tocheck == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	else if (char_tocheck == 'p')
	{
		int retprefix = ft_putstr("0x");
		return (retprefix + ft_addresstohex(va_arg(list_arg, unsigned long), basehex));
	}
	else if (char_tocheck == 'd' || char_tocheck == 'i')
		return (ft_putstr(ft_itoa(va_arg(list_arg, int))));
	else if (char_tocheck == 'u')
		return (ft_putstr(ft_unsigneditoa(va_arg(list_arg, unsigned int))));
	else if (char_tocheck == 'x')
		return (ft_unsignedtohex(va_arg(list_arg, unsigned int), basehex));
	else if (char_tocheck == 'X')
	{
		char *baseUppercase = ft_strmapi(basehex, ft_toupper);
		return (ft_unsignedtohex(va_arg(list_arg, unsigned int), baseUppercase));
	}
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

