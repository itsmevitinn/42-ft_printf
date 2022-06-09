#include "ft_printf.h"

int size_unsignedhex(unsigned int address)
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
char *print_unsignedhex(unsigned int address, char *hexbase)
{
	int sizehex;
	char *converted;
	sizehex = size_unsignedhex(address);
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
int ft_unsignedtohex (unsigned int address, char *hexbase)
{
	printf("address -1: %u\n", address);
	char *converted;
	int size_string;
	converted = print_unsignedhex(address, hexbase);
	//acrescento +1 pois eu printo uma string e retorno o tamanho da string + 1 do nulo
	size_string = ft_putstr(converted);
	return (size_string);
}
