/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:38:45 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/17 19:39:44 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdio.h>
#include "../libft/libft.h"

int			check_flags(const char *format, t_params *params)
{
	int	i;

	i = 0;
	params->flags = NO_FLAGS;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			params->flags = params->flags | MINUS_FLAG;
		if (format[i] == '0')
			params->flags = params->flags | ZIRO_FLAG;
		i++;
	}
	return (i);
}

int			check_width(const char *format, t_params *params, va_list args)
{
	int	i;

	i = 0;
	if (format[i] == '*')
	{
		params->width = va_arg(args, int);
		if (params->width < 0)
		{
			params->width = -params->width;
			params->flags = params->flags | MINUS_FLAG;
		}
		return (++i);
	}
	if (!(format[i] >= '1' && format[i] <= '9'))
	{
		params->width = -1;
		return (i);
	}
	params->width = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		params->width = params->width * 10 + (format[i] - 48);
		i++;
	}
	return (i);
}

int			check_accuracy(const char *format, t_params *params, va_list args)
{
	int	i;

	i = 0;
	if (format[i] != '.')
	{
		params->accuracy = -1;
		return (i);
	}
	i++;
	if (format[i] == '*')
	{
		params->accuracy = va_arg(args, int);
		return (++i);
	}
	while (format[i] == '0')
		i++;
	if (format[i] < '1' || format[i] > '9')
	{
		params->accuracy = 0;
		return (i);
	}
	params->accuracy = 0;
	while (format[i] >= '0' && format[i] <= '9')
		params->accuracy = params->accuracy * 10 + (format[i++] - 48);
	return (i);
}

void		get_type(const char *format, t_params *params)
{
	int	i;

	i = 0;
	while (g_types[i])
	{
		if (!(ft_strncmp(g_types[i], format, ft_strlen(g_types[i]))))
		{
			params->type = (char*)g_types[i];
			params->is_correct = 1;
			return ;
		}
		i++;
	}
	if (!params->type)
	{
		params->type = NULL;
		params->is_correct = 0;
	}
}

t_params	*ft_parser(const char *format, va_list args)
{
	t_params		*params;
	int				i;

	params = (t_params*)malloc(sizeof(t_params) * 1);
	i = check_flags(format, params);
	i += check_width(&format[i], params, args);
	i += check_accuracy(&format[i], params, args);
	get_type(&format[i], params);
	if (params->is_correct)
	{
		i += ft_strlen(params->type);
		params->size = i;
		return (params);
	}
	free(params);
	return (NULL);
}
