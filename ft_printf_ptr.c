/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:21:53 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/09 20:22:35 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_pointer(char *buf, size_t n, int **count)
{
	char	*res;
	char	*str;
	char	*src;

	if (n == 0)
		*(*count) += 5;
	else
		*(*count) += 2;
	if (n == 0 && !buf)
		return (ft_strdup("(nil)"));
	else if (n == 0 && *buf)
		return (res = ft_strjoin(buf, "(nil)"), free(buf), res);
	else if (buf)
	{
		str = ft_strdup("0x");
		src = ft_utoa(str, n, "0123456789abcdef", count);
		return (res = ft_strjoin(buf, src), free(buf), free(src), res);
	}
	else
	{
		buf = ft_utoa(buf, n, "0123456789abcdef", count);
		return (res = ft_strjoin("0x", buf), free(buf), res);
	}
}
