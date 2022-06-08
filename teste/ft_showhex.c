/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:51:20 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/08 00:20:25 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
int hex_number (unsigned long nbr)
{
	int i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}
#include <stdio.h>
char *ft_stringhex(unsigned long nbr, char *toconvert)
{
	printf("tamanho antes conversao: %lu\n", nbr);
	int i;
	int size;
	char *hex;
	i = 0;
	size = hex_number(nbr);
	hex = malloc(sizeof(char) * (size + 1));
	hex[size--] = '\0';
	while (size >= 0)
	{
		//ira preencher do fim ao inicio, o ponteiro a ser printado com algum caracter da base hexadecimal, e o index sera o nbr % 16;
		hex[size] = toconvert[nbr % 16];
		nbr = nbr / 16;
		size--;
	}
	return (hex);
}
#include <stdio.h>
int ft_showhex (unsigned long nbr, char *toconvert)
{
	char *str_hex;
	str_hex = ft_stringhex(nbr, toconvert);
	int len_hex;
	len_hex = ft_putstr(str_hex);
	printf("len printf: %i\n", len_hex);
	return (len_hex);
}
