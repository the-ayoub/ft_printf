/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelhaj <aybelhaj@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:52:31 by aybelhaj          #+#    #+#             */
/*   Updated: 2024/11/27 16:52:57 by aybelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

char		*ft_type(char c, va_list args, char *buf);
char		*montar_string(char *args, char *buf);
char		*montar(char *buf, char c);
char		*nmb(char *buf, int n);
char		*ft_itoa(int n);
static int	word_count(int n);

#endif
