/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:52:31 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/03 15:22:23 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		word_count(size_t n, int b);
int		ft_printf(const char *str, ...);
char	*ft_type(char c, va_list args, char *buf);
char	*montar_string(char *args, char *buf);
char	*montar(char *buf, char c);
char	*nmb(char *buf, int n);
char	*ft_utoa(char *buf, size_t nmb, char *base);
char	*ft_pointer(char *buf, size_t n);

#endif
