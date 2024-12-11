/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:27 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/11 16:18:00 by aybelhaj         ###   ########.fr       */
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
			buf = ft_type(str[++i], args, buf, &count);
		else
		{
			if (str[i] == '%' && str[i + 1] == '\0')
				return (write(1, buf, count), free(buf), -1);
			buf = build_char(buf, str[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count = write(1, buf, count), free(buf), count);
}

char	*ft_type(char c, va_list args, char *buf, int *count)
{
	if (c == 'c')
		return (build_char(buf, va_arg(args, int), count));
	if (c == 's')
		return (build_string(va_arg(args, char *), buf, &count));
	if (c == 'p')
		return (ft_pointer(buf, va_arg(args, size_t), &count));
	if (c == 'd' || c == 'i')
		return (nmb(buf, va_arg(args, int), &count));
	if (c == 'u')
		return (ft_utoa(buf, va_arg(args, unsigned int), "0123456789", &count));
	if (c == 'x')
		return (ft_utoa(buf, va_arg(args, unsigned int), "0123456789abcdef",
				&count));
	if (c == 'X')
		return (ft_utoa(buf, va_arg(args, unsigned int), "0123456789ABCDEF",
				&count));
	if (c == '%')
		return (build_char(buf, '%', count));
	return (0);
}
#include <stdio.h>
int main()
{
	char *b = NULL;
//	ft_printf("%d", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%% %p", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0, NULL));
	//ft_printf("%d", ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%% %p", 'A', "42", 42, 42 ,42 , 42, 42, 'B', NULL));
	ft_printf("%d\n", ft_printf("%s %c%% %s%c%s%c %s %","hola", 0,"adios", 0, "", 0, b));
	printf("%d\n", printf("%s %c%% %s%c%s%c %s %","hola", 0,"adios", 0, "", 0, b));
	ft_printf("%d\n", ft_printf("hola%chola", 0));
	printf("%d", printf("hola%chola", 0));

	
//	printf("%d", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%% %p", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0, NULL));
	//printf("%d", printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%% %p", 'A', "42", 42, 42 ,42 , 42, 42, 'B', NULL));

}
