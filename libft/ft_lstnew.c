/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:57 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/02 18:14:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/// @brief 	Allocates (with malloc(3)) and returns a new node.
///			The member variable ’content’ is initialized with
///			the value of the parameter ’content’. The variable
///			’next’ is initialized to NULL.
/// @param content 	The content to create the node with.
/// @return			The new node.
t_list	*ft_lstnew(void *content)
{
	t_list	*sl1;

	sl1 = (t_list *)malloc(sizeof(t_list));
	if (sl1 == NULL)
		return (0);
	sl1->content = content;
	sl1->next = NULL;
	return (sl1);
}
