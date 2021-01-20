/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:02:59 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/07 22:48:10 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define NO_FLAGS	0b00000000
# define ZIRO_FLAG	0b00000001
# define MINUS_FLAG	0b00000010

static	const	char	*g_types[] =
{
	"c",
	"s",
	"p",
	"i",
	"d",
	"u",
	"x",
	"X",
	"%",
	NULL
};

typedef	struct		s_params
{
	unsigned char	flags;
	int				width;
	int				accuracy;
	int				size;
	char			*type;
	short			is_correct;
}					t_params;

t_params			*ft_parser(const char *format, va_list args);

#endif
