/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:59:20 by aysozen           #+#    #+#             */
/*   Updated: 2023/01/14 21:16:28 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
	{
		while (n--)
			*((unsigned char *)(dst + n)) = *((unsigned char *)(src + n));
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
 	char str[] = "kocaeli";

 	printf("%s\n",(char *)ft_memmove(str+2,str,3));
	printf("%s\n",(char *)memmove(str+2, str, 3));
}
*/