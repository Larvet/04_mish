/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:25:34 by bchene            #+#    #+#             */
/*   Updated: 2023/11/18 20:26:17 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	putvalchar(va_list valist);
int	putvalstring(va_list valist);
int	putvalpercent(void);

int	putintvarg(int n);
int	putvalint(va_list valist);
int	putunsignedintvarg(unsigned int n);
int	putvalunsignedint(va_list valist);

int	puthexavarg(unsigned long long n, char c);
int	putvalpointer(va_list valist);
int	putvalhexa(va_list valist, char c);

int	putnextval(const char c, va_list valist, int ret);
int	ft_printf(const char *format, ...);

#endif
