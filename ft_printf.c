/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:21:09 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/07 00:30:11 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int check_options(va_list list_arg, const char check_option)
{
	int printf_add;

	printf_add = 0;
	if (check_option == 's')
		return (ft_putstr(va_arg(list_arg, char *)));
	if (check_option == '%')
		return (ft_putchar('%'));
	else if(check_option == 'c')
		return (ft_putchar(va_arg(list_arg, int)));
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
	return (printf_result);
}

int main(void)
{
	char *nome = "Viitor";
	int testeretorno = ft_printf("printf de teste: %s\n", nome);
	ft_printf("eae %s", nome);
	printf("\n");
	printf("eae %s\n", nome);
	printf("retorno do teste: %i", testeretorno);
}
