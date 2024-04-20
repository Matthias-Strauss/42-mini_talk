/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:39:05 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	pf_tohexlower(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = pf_tohexlower(n / 16);
	if (i == -1)
		return (-1);
	return (write(1, &"0123456789abcdef"[n % 16], 1) + i);
}

int	pf_tohexupper(unsigned long n)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = pf_tohexupper(n / 16);
	if (i == -1)
		return (-1);
	return (write(1, &"0123456789ABCDEF"[n % 16], 1) + i);
}
