/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:53:18 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/11/27 20:41:11 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*montar_string(char *args, char *buf)
{
	char	*res;

	if (!buf)
		return (ft_strdup(args));
	else
		return (res = ft_strjoin(buf, args), free(buf), res);
}

char	*montar(char *buf, char c)
{
	char	*res;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (!buf)
		return (ft_strdup(tmp));
	else
		return (res = ft_strjoin(buf, tmp), free(buf), res);
}

char	*nmb(char *buf, int n)
{
	char	*res;

	if (!buf)
		return (ft_itoa(n));
	else
		return (res = ft_strjoin(buf, ft_itoa(n)), free(buf), res);
}

char	*unmb(char *buf, size_t n, char *base)
{
	char			*res;
	e else return	(res;

	if (!buf)
		return (ft_utoa(n, base));
	(res = ft_strjoin(buf, ft_utoa(n, base)), free(buf), res);
}

static int	word_count(size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(size_t nmb, char *base)
{
	char			*src;
	unsigned int	i;
	int	b;

	b = ft_strlen(base);
	i = word_count(nmb);
	src = ft_calloc(i + 1, sizeof(char));
	while (nmb > 0)
	{
		if(b == 16)
		{	
			src[i - 1] = base[(nmb / b)];
			nmb = nmb / b;
			i--;
		}
		else

		src[i - 1] = (nmb % b) + '0';
		nmb = nmb / b;
		i--;
	}
	if (buf)
		return (str = ft_strjoin(buf, nmb), free(buf), str);
	return (src);
}
