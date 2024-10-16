/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis_III.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:23:32 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/16 15:34:43 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (true);
	while (s[++i] && s[i] != '\n')
	{
		if (s[i] != ' ' && s[i] != '1')
			return (false);
	}
	return (true);
}

bool	onlynl(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (true);
	while (s[++i])
	{
		if (s[i] == '\n' || s[i] == ' ')
			continue ;
		else
			return (false);
	}
	return (true);
}

bool	ft_preprocess(t_line *lines)
{
	while (lines && !is_map(lines->s))
		lines = lines->next;
	while (lines && onlynl(lines->s))
		lines = lines->next;
	while (lines)
	{
		if (onlynl(lines->s))
			return (false);
		lines = lines->next;
	}
	return (true);
}

// make the real line2path _|[-_-]|_ i see u
char	*line2path(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	while (*s && !ft_isspace(*s))
		s++;
	while (*s && ft_isspace(*s))
		s++;
	return (ft_strdup(s));
}

char	*skip(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}
