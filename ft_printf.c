/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:27 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/11/27 20:41:14 by aybelhaj         ###   ########.fr       */
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
	return (count = write(1, buf, ft_strlen(buf)), free(buf), count);
}

char	*ft_type(char c, va_list args, char *buf)
{
	if (c == 'c')
		return (montar(buf, va_arg(args, int)));
	if (c == 's')
		return (montar_string(va_arg(args, char *), buf));
	// if(c == 'p')
	if (c == 'd' || c == 'i')
		return (nmb(buf, va_arg(args, int)));
	if (c == 'u')
			return(unmb(buf,va_arg(args,unsigned int), "0123456789");
	// if(c == 'x')
	//		return(unmb(buf,va_arg(args,unsigned int), "0123456789abcdef");
	//		ft_utoa (buf,va_arg(args,unsigned int));
	// if(c == 'x')
	//		ft_utoa (buf,va_arg(args,unsigned int));
	if (c == '%')
		return (montar(buf, '%'));
}
int	main(void)
{
	char	a;
	char	*b;

	a = '&';
	b = "ayoub";
	//	c = 125548;
	// printf("\n%i", ft_printf("hola  %c%%", a));
	//	ft_printf("%i", ft_printf("hola%%"));
	ft_printf("hola %c %s", a, b);
	// ft_printf("%i", ft_printf("hola%i\n", c));
}
