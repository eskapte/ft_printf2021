/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:31:36 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/17 19:59:58 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

int		ui_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*str_ui(unsigned int ui)
{
	int		len;
	char	*num;

	len = ui_len(ui);
	num = malloc(len + 1);
	if (!num)
		return (0);
	num[len--] = '\0';
	while (len >= 0)
	{
		num[len--] = (ui % 10) + '0';
		ui = ui / 10;
	}
	return (num);
}

int		unsigned_handler(unsigned int ui, t_params *params)
{
	char	*str;
	int		len;

	str = (ui == 0 && params->accuracy == 0) ? ft_strdup("") : str_ui(ui);
	len = ft_strlen(str);
	if (params->accuracy > len)
		str = join_and_free(fill_str(params->accuracy - len, ZIRO_FLAG), str);
	if (params->width > (int)ft_strlen(str))
	{
		len = ft_strlen(str);
		if (params->flags & MINUS_FLAG)
			str = join_and_free(str, fill_str(params->width - len, MINUS_FLAG));
		else if (params->accuracy != -1)
			str = join_and_free(fill_str(params->width - len, MINUS_FLAG), str);
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
