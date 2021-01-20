/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:51:47 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/20 20:10:55 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

int		pointer_handler(unsigned long long p, t_params *params)
{
	char	*str;
	int		len;

	str = convert_to_16x(p, 0);
	len = ft_strlen(str);
	if (params->accuracy > (int)ft_strlen(str))
		str = join_and_free(fill_str(params->accuracy - len, ZIRO_FLAG), str);
	str = join_and_free(ft_strdup("0x"), str);
	if (params->width > (int)(len = ft_strlen(str)))
	{
		if (params->flags & MINUS_FLAG)
			str = join_and_free(str, fill_str(params->width - len, MINUS_FLAG));
		else if (params->flags & ZIRO_FLAG)
			str = join_and_free(fill_str(params->width - len, ZIRO_FLAG), str);
		else
			str = join_and_free(fill_str(params->width - len, NO_FLAGS), str);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
