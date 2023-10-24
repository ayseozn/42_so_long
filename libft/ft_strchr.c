/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:20:59 by aysozen           #+#    #+#             */
/*   Updated: 2023/01/14 23:42:49 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*s = "aysseee";
	int	c = 's';

	printf("ft_strchr: %s\n", ft_strchr(s, c));
	printf("strchr: %s\n", strchr(s, c));
}
*/