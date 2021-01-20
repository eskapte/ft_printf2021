/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhawick <lhawick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:02:18 by lhawick           #+#    #+#             */
/*   Updated: 2021/01/17 20:01:09 by lhawick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

char	*fill_str(int len, unsigned char flag)
{
	char	*str;
	int		i;

	i = 0;
	if (len <= 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		if (flag & MINUS_FLAG)
			str[i] = ' ';
		else if (flag & ZIRO_FLAG)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

char	*get_s(const char *str, t_params *params)
{
	char	*s;

	if (params->accuracy == 0)
		s = ft_strdup("");
	else if (!str)
	{
		if (params->accuracy > 0 && params->accuracy < (int)ft_strlen("(null)"))
		{
			s = (char*)malloc(sizeof(char) * params->accuracy);
			ft_strlcpy(s, "(null)", params->accuracy + 1);
		}
		else
			s = ft_strdup("(null)");
	}
	else if (params->accuracy > 0 && params->accuracy < (int)ft_strlen(str))
	{
		s = (char*)malloc(sizeof(char) * params->accuracy);
		ft_strlcpy(s, str, params->accuracy + 1);
	}
	else
		s = ft_strdup(str);
	return (s);
}

int		str_handler(const char *str, t_params *params)
{
	char	*s;
	int		len;

	s = get_s(str, params);
	if (params->width > (len = (int)ft_strlen(s)))
	{
		if (params->flags & MINUS_FLAG)
			s = join_and_free(s, fill_str(params->width - len, MINUS_FLAG));
		else if (params->flags & ZIRO_FLAG)
			s = join_and_free(fill_str(params->width - len, ZIRO_FLAG), s);
		else
			s = join_and_free(fill_str(params->width - len, NO_FLAGS), s);
	}
	len = (int)ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
