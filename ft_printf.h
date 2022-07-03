/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:26:12 by vsergio           #+#    #+#             */
/*   Updated: 2022/07/03 19:06:02 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *string, ...);

char	*ft_utoa(unsigned int n);

char	*ft_ultohex(unsigned long address, char *hexbase);

int		ft_putchar_int(char c);

int		ft_putstr_int(char *s);

int		size_and_print_uint(va_list list_arg, char check);

int		size_and_print_int(va_list list_arg);

int		size_and_print_hex(va_list list_arg, char *basehex, char check);

#endif
