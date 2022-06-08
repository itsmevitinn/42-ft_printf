#include "ft_printf.h"
int size_hex(unsigned long address)
{
	int len;

	len = 0;
	if (address == 0)
	{
		len = 1;
		return (len);
	}
	while (address > 0)
	{
		address = address / 16;
		len++;
	}
	return (len);
}
#include <stdio.h>
char *ft_printhex(unsigned long address, char *hexbase)
{
	int sizehex;
	char *converted;
	int i;
	i = 0;
	sizehex = size_hex(address);
	converted = malloc(sizeof(char) * (sizehex + 1));
	if (address == 0)
	{
		converted[sizehex--] = '\0';
		converted[sizehex] = '0';
		return (converted);
	}
	converted[sizehex--] = '\0'; 
	while (sizehex >= 0)
	{
		converted[sizehex] = hexbase[address % 16];
		address = address / 16;
		sizehex--;
	}
	return (converted);
}
#include <stdio.h>
int ft_addresstohex (unsigned long address, char *hexbase)
{
	char *converted;
	int size_string;
	converted = ft_printhex(address, hexbase);
	//acrescento +1 pois eu printo uma string e retorno o tamanho da string + 1 do nulo
	size_string = ft_putstr(converted);
	return (size_string);
}
