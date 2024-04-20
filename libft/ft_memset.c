/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:44:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief writes len bytes of value c (as an unsigned char) to the string b
/// @param b	pointer to the string to be searched
/// @param c 	the character to be written to string
/// @param len 	amount of bytes of c to write
/// @return		its first argument
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	*d;

	i = 0;
	d = b;
	while (i < len)
		d[i++] = (unsigned char)c;
	return (b);
}
