/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:05:16 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/06 21:11:35 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
void	woman(char **dishes)
{
	int	i;

	i = 0;
	while (dishes[i])
	{
		free(dishes[i]);
		i++;
	}
	free(dishes);
}

static
void	initializer(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

static
char	**stuffing(char **strs, const char *s, char c)
{
	int		i;
	int		j;
	char	buff[70000];
	int		elements;

	initializer(&i, &elements);
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
				woman(strs);
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
	int			elements;
	char		**strs;

	if (!s)
		return (NULL);
	elements = cw(s, c);
	strs = malloc((elements + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	elements = 0;
	strs = stuffing(strs, s, c);
	if (!strs)
		return (NULL);
	strs[cw(s, c)] = 0;
	return (strs);
}
