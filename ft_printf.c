/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:21:09 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/07 11:02:09 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int check_options(va_list list_arg, const char check_option)
{
	int printf_add;

	printf_add = 0;
	if (check_option == '%')
		return (ft_putchar('%'));
	else if(check_option == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
	else if (check_option == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	// por que devemos converter o enderecamento para hexadecimal?
	//pois o enderecamento eh binario (i.g) 0101001001010101, entao convertemos para hexadecimal
	//para ser mais entendivel por um humano
	// else if (check_option == 'p')
		// return (ft_hex_adress(va_arg(list_arg, unsigned long)));
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
	char rato = 'c';
	char *nome = "Viitor";
	int testeadress = ft_printf("%p", &rato);
	int testeretorno = ft_printf("printf de teste: %s\n", nome);
	ft_printf("eae %s %p", nome);
	printf("\n");
	printf("eae %s\n", nome);
	printf("retorno adress: %i\n", testeadress);
	printf("retorno do teste: %i", testeretorno);
}
