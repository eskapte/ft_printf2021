/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:24:57 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/20 21:47:47 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

char	*fill_ziro(char *str, int cnt)
{
	char	*new_str;

	if (str[0] == '-')
	{
		new_str = ft_strdup(&str[1]);
		new_str = join_and_free(fill_str(cnt, ZIRO_FLAG), new_str);
		new_str = join_and_free(ft_strdup("-"), new_str);
		free(str);
	}
	else
		new_str = join_and_free(fill_str(cnt, ZIRO_FLAG), str);
	return (new_str);
}

int		int_handler(int num, t_params *params)
{
	char	*str;
	int		len;

	str = (num == 0 && params->accuracy == 0) ? ft_strdup("") : ft_itoa(num);
	len = (num < 0) ? (int)ft_strlen(str) - 1 : (int)ft_strlen(str);
	if (params->accuracy > len)
		str = fill_ziro(str, params->accuracy - len);
	if (params->width > (int)ft_strlen(str))
	{
		len = ft_strlen(str);
		if (params->flags & MINUS_FLAG)
			str = join_and_free(str, fill_str(params->width - len, MINUS_FLAG));
		else if (params->accuracy != -1)
			str = join_and_free(fill_str(params->width - len, MINUS_FLAG), str);
		else if (params->flags & ZIRO_FLAG)
			str = fill_ziro(str, params->width - len);
		else
			str = join_and_free(fill_str(params->width - len, NO_FLAGS), str);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
