/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:12:11 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/06 21:18:31 by mel-akar         ###   ########.fr       */
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


