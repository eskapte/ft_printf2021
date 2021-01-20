/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:28:36 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/20 20:12:55 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLER_H
# define FT_HANDLER_H

# include "../libft/libft.h"
# include "../parser/ft_parser.h"
# include "unistd.h"

void	ft_handler(const char *format, int *i, int *size, va_list args);
int		char_handler(char ch, t_params *params);
char	*fill_str(int len, unsigned char flag);
char	*join_and_free(char *s1, char *s2);
int		write_space(int count);
int		str_handler(const char *str, t_params *params);
int		int_handler(int num, t_params *params);
int		pointer_handler(unsigned long long p, t_params *params);
int		unsigned_handler(unsigned int ui, t_params *params);
int		percent_handler();
int		hex_handler(unsigned int hex, int big, t_params *params);
char	*reverse_arr(char *arr);
char	*convert_to_16x(unsigned long long num, int big);

#endif
