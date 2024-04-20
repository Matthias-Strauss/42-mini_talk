/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static unsigned long	ft_posnum(int n)
{
	if (n < 0)
		return ((unsigned long)n * -1);
	else
		return ((unsigned long)n);
}

static void	ft_helper(unsigned long n, unsigned long fd)
{
	if (n >= 10)
		ft_helper(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

/// @brief 		Outputs the integer ’n’ to the given file descriptor.
/// @param n 	Integer to output.
/// @param fd 	File descriptor on which to write.
void	ft_putnbr_fd(int n, int fd)
{
	unsigned long	n_unsg;

	if (n < 0)
		ft_putchar_fd('-', fd);
	n_unsg = ft_posnum(n);
	ft_helper(n_unsg, fd);
}
