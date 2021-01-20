/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:33:00 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/17 19:40:33 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_handler.h"
#include "../parser/ft_parser.h"
#include "../libft/libft.h"

int		write_and_size(t_params *params, va_list args)
{
	if (!(ft_strncmp(params->type, "c", 1)))
		return (char_handler(va_arg(args, int), params));
	else if (!(ft_strncmp(params->type, "s", 1)))
		return (str_handler(va_arg(args, char *), params));
	else if (!(ft_strncmp(params->type, "p", 1)))
		return (pointer_handler(va_arg(args, unsigned long long), params));
	else if (!(ft_strncmp(params->type, "i", 1)))
		return (int_handler(va_arg(args, int), params));
	else if (!(ft_strncmp(params->type, "d", 1)))
		return (int_handler(va_arg(args, int), params));
	else if (!(ft_strncmp(params->type, "u", 1)))
		return (unsigned_handler(va_arg(args, unsigned int), params));
	else if (!(ft_strncmp(params->type, "x", 1)))
		return (hex_handler(va_arg(args, unsigned int), 0, params));
	else if (!(ft_strncmp(params->type, "X", 1)))
		return (hex_handler(va_arg(args, unsigned int), 1, params));
	else if (!(ft_strncmp(params->type, "%", 1)))
		return (percent_handler(params));
	return ((int)NULL);
}

void	ft_handler(const char *format, int *i, int *size, va_list args)
{
	t_params	*params;

	params = ft_parser(format, args);
	if (params && params->is_correct)
	{
		*i += params->size;
		*size += write_and_size(params, args);
		free(params);
		return ;
	}
	else
		*size = -1;
}
