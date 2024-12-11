/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:53:18 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/11 16:10:57 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*char	*build_string(char *args, char *buf, int **count)
{
	char	*res;

	if (args)
		*(*count) += ft_strlen(args);
	else
		*(*count) += 6;
	if (!buf && args)
		return (ft_strdup(args));
	else if (!args && buf)
		return (res = ft_strjoin(buf, "(null)"), free(buf), res);
	else if (!args && !buf)
		return (ft_strdup("(null)"));
	else
		return (res = ft_strjoin(buf, args), free(buf), res);
}*/
char	*build_string(char *args, char *buf, int **count)
{
	char	*tmp;
	if (args)
		tmp = args;
	else
		tmp = "(null)";
	while (*tmp)
	{
		buf = build_char(buf, *tmp, *count);
		tmp++;
	}
	return(buf);
}

char	*build_char(char *buf, char c, int *len)
{
	char	*res;

	res = ft_calloc(*len + 2, sizeof(char));
	if (buf)
	{
		ft_memcpy(res, buf, *len);
		free(buf);
	}
	res[(*len)++] = c;
	res[*len] = '\0';
	return (res);
}

char	*nmb(char *buf, int n, int **count)
{
	char	*res;
	char	*nb;

	nb = ft_itoa(n);
	*(*count) += ft_strlen(nb);
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

char	*ft_utoa(char *buf, size_t nmb, char *base, int **count)
{
	char			*src;
	unsigned int	i;
	int				b;
	char			*str;

	b = ft_strlen(base);
	i = word_count(nmb, b);
	*(*count) += i;
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
