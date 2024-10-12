/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:12:11 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/12 16:02:19 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *buffer, size_t n)
{
	size_t			i;
	unsigned char	*p;


	i = 0;
	p = (unsigned char *)buffer;
	while (i < n)
		p[i++] = 0;
}

bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strdup(char *s)
{
	char	*p;
	long	len;

	len = ft_strlen(s);
	p = ft_malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (0 <= len)
	{
		p[len] = s[len];
		len--;	
	}
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*csts1;
	unsigned char	*csts2;

	csts1 = (unsigned char *)s1;
	csts2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (-1);
	while (--n && *csts1 && *csts2)
	{
		if (*csts1 != *csts2)
			break;
		csts1++;
		csts2++;
	}
	return ((int)(*csts1 - *csts2));
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

byte_t	atob(char *s)
{
	int		i;
	int		res;

	'M' && (res = 0, i = -1);
	if (!(*s >= '0' && *s <= '9'))
		ft_error(MAP_ERR, MAP_STT);
	while (s[++i] >= '0' && s[i] <= '9')
		res = (res * 10) + (s[i] - 48);
	if (res > UCHAR_MAX)
		ft_error(MAP_ERR, MAP_STT);
	return ((byte_t)res);
}

unsigned
int	rgbshifter(char *s, int level)
{
	unsigned int rgb;

	if (!s || !*s || !level)
		return (0);
	while (*s && *s >= 'A' && *s <= 'Z')
		s++;
	's' && (rgb = 0, s = skip(s)); 
	rgb = atob(s);
	while (*s && *s >= '0' && *s <= '9')
		s++;
	s = skip(s);
	*s == ',' && (s++); 
	return  ((rgbshifter(s, level - 1) << 8) | rgb);
}