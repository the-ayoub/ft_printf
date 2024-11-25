/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:04:27 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/11/24 03:12:16 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_type(char c, va_list args, char *buf, int *count);
size_t	ft_strlen(const char *s);
char	*montar_string(char *args, char **buf, int *count);
char	*montar(char *buf, char c);

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	char 	*buf;
	va_list	args;

	i = 0;
	count = 0;
	buf = 0;
	va_start(args, str);
	if(!*str)
		return(0);
	while (str[i])
	{
		if(str[i] == '%' && str[i + 1])
		{
			i++;
			buf = ft_type(str[i], args, buf, &count);
		}
		else
		{
			buf = montar(buf, str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return	(write(1, buf, count),free(buf), count);
}

char	*ft_type(char c, va_list args, char *buf, int *count)
{
	char	*res = NULL;

	if(c == 'c')
	{
		res = montar(buf, va_arg(args, int));
		(*count)++;
	}
	if(c == 's')
		res = montar_string(va_arg(args, char *), &buf, count);
	/*if(c == 'p')
	if(c == 'd' || c == 'i')
		
	if(c == 'u')
	if(c == 'x')
	if(c == 'X')*/
	if(c == '%')
	{
		res = montar(buf,  '%');
		(*count)++;
	}
	return(res);
}

char	*montar_string(char *args, char **buf, int *count)
{
	char	*res = NULL;
	int	i;
	int	j;
	if (!buf)
	{
		res = malloc(ft_strlen(args) * sizeof(char));
		if(!res)
			return(0);
		i = 0;
		while(args[i])
		{
			res[i] = args[i];
			(*count)++;
			i++;
		}
		res[i] = '\0';
	}
	else
	{
		res = malloc((ft_strlen(*buf) + ft_strlen(args) + 1) * sizeof(char));
		if(!res)
			return(0);
		i = 0, j = 0;
		while ((*buf)[i])
		{
			res[i] = (*buf)[i];
			i++;
		}
		while(args[j])
		{
			res[i + j] = args[j];
			(*count)++;
			j++;
		}
		res[i + j] = '\0';
		free(*buf);
	}
	return (res);
}

char	*montar(char *buf, char c)
{
	int	i;
	char	*res = NULL;
	if (!buf)
	{
		res = malloc(2 * sizeof(char));
		if (!res)
			return(0);
		res[0] = c;
		res[1] = '\0';
	}
	else
	{
		i = -1;
		res = malloc((ft_strlen(buf) + 2) * sizeof(char)); 
		while (buf[++i])
			res[i] = buf[i];
		free(buf);
		res[i++] = c;
		res[i] = '\0';
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

int main(void)
{
	char a = 'h';
//	char *b = "ayoub";
	printf("\n%i", ft_printf("hola  %c%%", a));
//	ft_printf("%i", ft_printf("hola%%"));
	//ft_printf("ho");
}
