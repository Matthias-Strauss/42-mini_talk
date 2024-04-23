/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:01:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/22 22:22:38 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	w_kill(pid_t pid, int i)
{
	if (kill(pid, i) == -1)
	{
		ft_putstr_fd("ERROR: Sending signal failed. kill() returned -1", 1);
		exit(1);
	}
}

void	check_pid(pid_t pid, char *str)
{
	int	i;

	i = 0;
	if (pid < 0)
	{
		pf_printf("Negative Server PID.\n");
		exit(3);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i++]) == 0)
		{
			pf_printf("Non digit characters in Server PID.\n");
			exit(3);
		}
	}
}
