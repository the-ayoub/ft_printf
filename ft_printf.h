/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:52:31 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/12/10 15:46:14 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		word_count(size_t n, int b);
int		ft_printf(const char *str, ...);
char	*ft_type(char c, va_list args, char *buf, int *count);
char	*build_string(char *args, char *buf, int **count);
char	*build_char(char *buf, char c, int *len);
char	*nmb(char *buf, int n, int **count);
char	*ft_utoa(char *buf, size_t nmb, char *base, int **count);
char	*ft_pointer(char *buf, size_t n, int **count);

#endif
