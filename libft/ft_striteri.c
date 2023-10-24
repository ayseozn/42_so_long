/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <42kocaeli.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:40:14 by aysozen           #+#    #+#             */
/*   Updated: 2023/01/14 16:42:24 by aysozen          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
void	ft_42(unsigned int a, char *c)
{
	(void) a;
	*c = ft_toupper(*c);
}

#include <stdio.h>

int main()
{
	char str[] = "Merhaba42";
	printf("%s\n", str);
	ft_striteri(str, ft_42);
	printf("%s\n", str);
}
*/
