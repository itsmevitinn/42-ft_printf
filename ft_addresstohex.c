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
char *ft_addresstohex(unsigned long address, char *hexbase)
{
	int sizehex;
	char *converted;
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
