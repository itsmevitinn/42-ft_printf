/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:26:12 by vsergio           #+#    #+#             */
/*   Updated: 2022/06/13 12:09:49 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *string, ...);

char	*ft_unsigneditoa(unsigned int n);

char	*ft_unsignedtohex(unsigned long address, char *hexbase);

int		ft_putchar_int(char c);

int		ft_putstr_int(char *s);

int		size_and_print_int(va_list list_arg);

int		size_and_print_unsigned(va_list list_arg);

int		size_and_print_hex(va_list list_arg, char *basehex, char check);

#endif
