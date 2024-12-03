/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:27 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/03 19:02:26 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	char	*buf;
	va_list	args;

	i = 0;
	buf = 0;
	count = 0;
	va_start(args, str);
	if (!*str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			buf = ft_type(str[i], args, buf);
		}
		else
			buf = montar(buf, str[i]);
		i++;
	}
	va_end(args);
	return (count = write(1, buf, 2), free(buf), count);
}

char	*ft_type(char c, va_list args, char *buf)
{
	if (c == 'c')
		return (montar(buf, va_arg(args, int)));
	if (c == 's')
		return (montar_string(va_arg(args, char *), buf));
	if (c == 'p')
		return (ft_pointer(buf, va_arg(args, size_t)));
	if (c == 'd' || c == 'i')
		return (nmb(buf, va_arg(args, int)));
	if (c == 'u')
		return (ft_utoa(buf, va_arg(args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_utoa(buf, va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_utoa(buf, va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (montar(buf, '%'));
	return (0);
}
#include <stdio.h>

int	main(void)
{
//	char	*b;
//	int		x;
//	char	a;
//	int		c;
//
//	// int str;
//	a = '&';
//	b = "ayoub";
//	x = 2147;
//	c = -548;
	//ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	ft_printf("%c\n", 0);
	// ft_printf("%c\n", 0);
	//ft_printf("%s", NULL);
	//ft_printf("null %s null", NULL);
	// free(printf("\n%i", ft_printf("hola  %c%%", a)));
	// ft_printf("%i", ft_printf("hola%%"));
	// ft_printf("%i",1ft_printf("hola %c %s\n", a, b));
//	ft_printf("hola%% c:%c s:%s U:%u d:%d x:%x X:%X\n", a, b, c, c, x, x);
	
//	ft_printf("valor: %p\n puntero 0:%p\n", &b, 0);
//	ft_printf("%p\n",0);
//	ft_printf("%p\n",&a);
//	ft_printf("hsakhds %c %s %d aak jskdj k", a, b, x);
}
