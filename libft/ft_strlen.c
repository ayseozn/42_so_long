/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:32:53 by aysozen           #+#    #+#             */
/*   Updated: 2023/10/21 18:04:04 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	d[] = "ayseayse";
	char	*s = d;

	printf("strlen: %lu\n", strlen(s));
	printf("ft_strlen: %lu\n", ft_strlen(s));
}
*/
