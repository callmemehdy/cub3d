/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_III.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:23:32 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/16 09:55:23 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

bool	ft_preprocess(t_linegnl *lines)
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
	if (!s)
		return (0);
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

char	*revskip(char *s)
{
	char	*tmp;

	if (!s)
		return (0);
	tmp = s + ft_strlen(s) - 1;
	while (tmp > s && ft_isspace(*tmp))
		tmp--;
	return (tmp);
}
