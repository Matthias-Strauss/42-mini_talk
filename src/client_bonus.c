/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:16 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/22 22:03:42 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_len(pid_t server_pid, unsigned int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & (1 << i++))
			w_kill(server_pid, SIGUSR1);
		else
			w_kill(server_pid, SIGUSR2);
		write(1, "pausing\n", 8);
		pause();
		usleep(10);
		pf_printf("%d unpausing (len)\n", i - 1);
	}
}

void	send_8bit(pid_t server_pid, int b)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (b & (1 << i++))
			w_kill(server_pid, SIGUSR1);
		else
			w_kill(server_pid, SIGUSR2);
		write(1, "pausing\n", 8);
		pause();
		usleep(10);
		pf_printf("%d unpausing\n", i);
	}
}

void	send_msg(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		pf_printf("Sending char:\t%c\n", str[i]);
		send_8bit(server_pid, str[i++]);
	}
	send_8bit(server_pid, '\0');
}

void	receive_acknowledgement(int sig, siginfo_t *info, void *ucontent)
{
	static int	i;

	(void)ucontent;
	(void)info;
	if (sig == SIGUSR1)
		pf_printf("\033[32m%d Receipt confirmed by server\033[0m\n", i++);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\033[34m\nEND OF TRANSMISSION\n\033[0m", 1);
		ft_putstr_fd("\033[34mClient terminated by server\n\033[0m", 1);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	unsigned int		len;
	struct sigaction	sig_act;

	if (argc != 3)
	{
		ft_putstr_fd("### ERROR ###\nUsage: ./client <SERVER_PID> <MESSAGE>\n",
			1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	check_pid(server_pid, argv[1]);
	len = ft_strlen(argv[2]);
	sig_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	sig_act.sa_sigaction = receive_acknowledgement;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	send_len(server_pid, len);
	// usleep(100);
	send_msg(server_pid, argv[2]);
	exit(0);
}
