/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:30:06 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief 		Checks if character is alphanumeric
/// @param c	Character to check
/// @return		One if true, Zero if false
int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}
