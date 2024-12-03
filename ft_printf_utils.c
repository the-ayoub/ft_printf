/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:53:18 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/03 17:35:31 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*montar_string(char *args, char *buf)
{
	char	*res;

	if (!buf && args)
		return (ft_strdup(args));
	else if (!args && buf)
		return (res = ft_strjoin(buf, "(null)"), free(buf), res);
	else if (!args && !buf)
		return (ft_strdup("(null)"));
	else
		return (res = ft_strjoin(buf, args), free(buf), res);
}

char	*montar(char *buf, char c)
{
	char	*res;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (!buf && c != '\0')
		return (ft_strdup(tmp));
	else if (c == '\0' && buf)
		return (res = ft_strjoin(buf, "\0"), free(buf), res);
	else if (c == '\0' && !buf)
		return (ft_strdup("\0"));
	else
		return (res = ft_strjoin(buf, tmp), free(buf), res);
}

char	*nmb(char *buf, int n)
{
	char	*res;
	char	*nb;

	nb = ft_itoa(n);
	if (!buf)
		return (nb);
	else
		return (res = ft_strjoin(buf, nb), free(nb), free(buf), res);
}

int	word_count(size_t n, int b)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / b;
		i++;
	}
	return (i);
}

char	*ft_utoa(char *buf, size_t nmb, char *base)
{
	char			*src;
	unsigned int	i;
	int				b;
	char			*str;

	b = ft_strlen(base);
	i = word_count(nmb, b);
	src = ft_calloc(i + 1, sizeof(char));
	src[0] = '0';
	while (nmb > 0)
	{
		src[i - 1] = base[nmb % b];
		nmb = nmb / b;
		i--;
	}
	if (buf)
		return (str = ft_strjoin(buf, src), free(buf), free(src), str);
	return (src);
}

char	*ft_pointer(char *buf, size_t n)
{
	char	*res;
	char	*str;
	char	*src;

	if (n == 0 && !buf)
		return (ft_strdup("(nil)"));
	else if (n == 0 && *buf)
		return (res = ft_strjoin(buf, "(nil)"), free(buf), res);
	else if (buf)
	{
		str = ft_strdup("0x");
		src = ft_utoa(str, n, "0123456789abcdef");
		return (res = ft_strjoin(buf, src), free(buf), free(src), res);
	}
	else
	{
		buf = ft_utoa(buf, n, "0123456789abcdef");
		return (res = ft_strjoin("0x", buf), free(buf), res);
	}
}
