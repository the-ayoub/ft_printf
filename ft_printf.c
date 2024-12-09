/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:27 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/09 21:35:33 by aybelhaj         ###   ########.fr       */
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
			buf = montar(buf, str[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count = write(1, buf, count), free(buf), count);
}

char	*ft_type(char c, va_list args, char *buf, int *count)
{
	if (c == 'c')
		return (montar(buf, va_arg(args, int), count));
	if (c == 's')
		return (montar_string(va_arg(args, char *), buf, &count));
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
		return (montar(buf, '%', count));
	return (0);
}
