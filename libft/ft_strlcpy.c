/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:47:56 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief 	strlcpy() copies up to dstsize - 1 characters from the string src to
/// 		dst, NUL-terminating the result if dstsize is not 0.
/// @param dst			destination string
/// @param src			source string
/// @param dstsize		size of dst INCLUDING Nul-termination
/// @return				length of source
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
