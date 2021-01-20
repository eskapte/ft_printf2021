/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:09:21 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/20 20:12:37 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

char	*reverse_arr(char *arr)
{
	char	new_arr[ft_strlen(arr) + 1];
	int		i;
	int		len;

	if (!arr)
		return (NULL);
	i = 0;
	len = ft_strlen(arr);
	while (i < len)
	{
		new_arr[i] = arr[len - i - 1];
		i++;
	}
	new_arr[i] = '\0';
	return (ft_strdup(new_arr));
}

char	*convert_to_16x(unsigned long long num, int big)
{
	char	str[32];
	int		mod;
	int		i;

	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (num > 0)
	{
		mod = num % 16;
		num = num / 16;
		str[i] = (big) ? "0123456789ABCDEF"[mod] :
							"0123456789abcdef"[mod];
		i++;
	}
	str[i] = '\0';
	return (reverse_arr(str));
}

int		hex_handler(unsigned int hex, int big, t_params *params)
{
	char	*str;
	int		len;

	str = (hex == 0 && params->accuracy == 0) ? ft_strdup("") :
												convert_to_16x(hex, big);
	len = ft_strlen(str);
	if (params->accuracy > (int)ft_strlen(str))
		str = join_and_free(fill_str(params->accuracy - len, ZIRO_FLAG), str);
	if (params->width > (int)(len = ft_strlen(str)))
	{
		if (params->flags & MINUS_FLAG)
			str = join_and_free(str, fill_str(params->width - len, MINUS_FLAG));
		else if (params->flags & ZIRO_FLAG && params->accuracy == -1)
			str = join_and_free(fill_str(params->width - len, ZIRO_FLAG), str);
		else
			str = join_and_free(fill_str(params->width - len, NO_FLAGS), str);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
