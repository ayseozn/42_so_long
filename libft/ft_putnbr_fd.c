/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysozen <aysozen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:06:24 by aysozen           #+#    #+#             */
/*   Updated: 2023/01/14 21:15:09 by aysozen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (nb * -1);
	}
	if (nb < 10)
		ft_putchar_fd(nb + 48, fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
/*
#include <fcntl.h>

int main()
{
//	int fd = open("/Users/sguntepe/Desktop/test.txt",O_WRONLY);
//	ft_putstr_fd("Merhaba ",fd);
	ft_putnbr_fd(42,1);
// 	ft_putstr_fd(" Kocaeli",fd);
}
*/