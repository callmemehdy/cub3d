/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:05:16 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/25 16:15:56 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static
int	cw(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static
void	namow(char **sehsid)
{
	int	i;

	i = 0;
	while (sehsid[i])
	{
		ft_free(sehsid[i]);
		i++;
	}
	ft_free(sehsid);
}

static
char	**stuffing(char **strs, const char *s, char c)
{
	int		i;
	int		j;
	char	buff[70000];
	int		elements;

	'M' && (i = 0, elements = 0);
	while (s[i])
	{
		j = 0;
		ft_bzero(buff, 70000);
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				buff[j++] = s[i++];
			strs[elements] = ft_strdup(buff);
			if (!strs[elements++])
			{
				namow(strs);
				return (NULL);
			}
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	char		**strs;
	int			elements;

	if (!s)
		return (NULL);
	elements = cw(s, c);
	strs = ft_malloc((elements + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = stuffing(strs, s, c);
	if (!strs)
		return (NULL);
	strs[elements] = 0;
	return (strs);
}
