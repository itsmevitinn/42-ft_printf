/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:21:09 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/08 00:18:57 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int check_options(va_list list_arg, const char check_option)
{
	int printf_add;
	char *base;
	base = "0123456789abcdef";
	printf_add = 0;
	if (check_option == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	if (check_option == '%')
		return (ft_putchar('%'));
	else if(check_option == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
	else if(check_option == 'p')
		return (ft_showhex(va_arg(list_arg, unsigned long), base));
	else
		return (0);
}

int ft_printf(const char *options, ...)
{
	va_list list_arg;
	int printf_result;
	va_start(list_arg, options);
	int i;

	i = 0;
	while(options[i])
	{
		if (options[i] == '%') 
		{
			printf_result += check_options(list_arg, options[i + 1]);
			i++;
		}
		else
			printf_result += ft_putchar(options[i]);		
		i++;
	}
	va_end(list_arg);
	//apesar da funcao printf escrever na tela, ela tambem retorna int, como testado na main abaixo.
	return (printf_result);
}

int main(void)
{
	char *nome = "Viitor";
	int testeretorno = ft_printf("printf de teste: %s\n", nome);
	printf("retorno do teste: %i\n", testeretorno);
	ft_printf("fake: %p\n", &nome);
	int a = printf("original: %p\n", &nome);
	printf("len original: %i", a);
}
