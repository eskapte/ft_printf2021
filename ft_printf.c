/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:05:45 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/20 21:48:01 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/ft_parser.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i] != '\0' && size >= 0)
	{
		if (format[i] != '%')
		{
			i += (int)write(1, &format[i], 1);
			size++;
		}
		else
			ft_handler(&format[++i], &i, &size, args);
	}
	va_end(args);
	return (size);
}
