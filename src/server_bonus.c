/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:15 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/20 15:40:42 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_flag;

inline void	w_kill(pid_t pid, int i)
{
	if (kill(pid, i) == -1)
	{
		ft_putstr_fd("ERROR: Sending confirmation failed. Kill returned -1", 1);
		exit(1);
	}
}

inline void	print_and_reset(char **str, int *str_ind, unsigned int len)
{
	write(1, *str, len);
	free(*str);
	*str = NULL;
	*str_ind = 0;
}

void	receive_8bits(int sig, siginfo_t *info, void *ucontent)
{
	static int	bit_ind;
	static int	str_ind;
	static char	*str;
	static char	c;

	(void)ucontent;
	printf("bit_ind:\t%d\nstr_ind:\t%d\nc:\t%c\nstr:\t%s\n\n", bit_ind, str_ind,
		c, str);
	if (sig == SIGUSR1)
		c = c | (1 << bit_ind++);
	else if (sig == SIGUSR2)
		bit_ind++;
	if (bit_ind == 8)
	{
		if (!str)
			str = ft_calloc(c + 1, 1);
		else
			str[str_ind++] = c;
		if (c == '\0')
			print_and_reset(&str, &str_ind, str_ind);
		bit_ind = 0;
		c = 0;
	}
	w_kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig_act;

	if (argc != 1)
		return (ft_putstr_fd("### ERROR ###\nUsage: ./server\n", 1), 1);
	(void)argv;
	sig_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sig_act.sa_sigaction = receive_8bits;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	pf_printf("PID: %d\n", getpid());
	while (WAHR)
		pause();
	exit(0);
}
