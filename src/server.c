/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:15 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/22 21:12:33 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_flag;

inline void	print_and_reset(char **str, int *str_ind, pid_t client_pid)
{
	pf_printf("\033[34m%s\033[0m", *str);
	free(*str);
	*str = NULL;
	*str_ind = 0;
	w_kill(client_pid, SIGUSR2);
}

char	*receive_len(int sig, pid_t client_pid, void *ucontent)
{
	static int			bit_ind;
	static unsigned int	len;
	unsigned int		tmp_len;
	char				*str;

	(void)client_pid;
	(void)ucontent;
	if (bit_ind == 0)
		len = 0;
	if (sig == SIGUSR1)
		len = len | (1 << bit_ind++);
	else if (sig == SIGUSR2)
		bit_ind++;
	if (bit_ind == 32)
	{
		tmp_len = len;
		bit_ind = 0;
		len = 0;
		str = ft_calloc(sizeof(char), tmp_len + 1);
		if (!str)
			exit(2);
		return (str);
	}
	return (NULL);
}

void	receive_8bits(int sig, siginfo_t *info, void *ucontent)
{
	static int	bit_ind;
	static int	str_ind;
	static char	*str;
	static char	c;

	if (!usleep(10) && !str)
		str = receive_len(sig, info->si_pid, ucontent);
	else if (sig == SIGUSR1)
		c = c | (1 << bit_ind++);
	else if (sig == SIGUSR2)
		bit_ind++;
	if (bit_ind == 8)
	{
		str[str_ind++] = c;
		if (c == '\0')
			print_and_reset(&str, &str_ind, info->si_pid);
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
	if (sigaction(SIGUSR1, &sig_act, NULL) < 0)
	{
		pf_printf("Assigning a sigaction to SIGUSR1 failed.\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sig_act, NULL) < 0)
	{
		pf_printf("Assigning a sigaction to SIGUSR2 failed.\n");
		exit(1);
	}
	pf_printf("PID: %d\n", getpid());
	while (WAHR)
		pause();
	exit(0);
}
