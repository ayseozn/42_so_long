/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:36:30 by aysozen           #+#    #+#             */
/*   Updated: 2023/01/14 21:15:49 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (!s)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	ft_42(unsigned int a, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (a);
}
/*
#include <stdio.h>

int main()
{
	char s[] = "merhaba";
	char *str;
 	str = ft_strmapi(s,ft_42);
	printf("%s",str);
}
*/