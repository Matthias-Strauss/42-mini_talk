/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:39:45 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/20 23:18:38 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief checks if a character is a digit
/// @param num character to check
/// @return returns character if it IS a digit
/// 		returns 0 if character is NOT a digit
int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (num);
	return (0);
}
