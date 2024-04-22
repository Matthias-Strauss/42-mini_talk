/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:56:44 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/22 19:12:49 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief 		Outputs the string ’s’ to the given file descriptor.
/// @param s	String to output.
/// @param fd	File descriptor on which to write.
inline void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
