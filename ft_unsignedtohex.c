/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedtohex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:04:53 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/10 18:06:12 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_unsignedhex(unsigned int address)
{
	int	len;

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

char	*ft_unsignedtohex(unsigned int address, char *hexbase)
{
	int		sizehex;
	char	*converted;

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
