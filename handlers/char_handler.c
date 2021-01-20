/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:35:46 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/16 12:16:08 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

int	write_space(int count)
{
	int	cnt;

	cnt = 0;
	while (cnt < count)
	{
		write(1, " ", 1);
		cnt++;
	}
	return (cnt);
}

int	char_handler(const char ch, t_params *params)
{
	int		size;

	size = 0;
	if (params->width > 1)
	{
		if (params->flags & MINUS_FLAG)
		{
			size += (int)write(1, &ch, 1);
			size += write_space(params->width - size);
		}
		else
		{
			size += write_space(params->width - size - 1);
			while (size < params->width - 1)
			{
				write(1, " ", 1);
				size++;
			}
			size += (int)write(1, &ch, 1);
		}
	}
	else
		size += (int)write(1, &ch, 1);
	return (size);
}
