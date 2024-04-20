/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:16 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/20 15:42:49 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	w_kill(pid_t pid, int i)
{
	if (kill(pid, i) == -1)
	{
		ft_putstr_fd("ERROR: Sending signal failed. Kill returned -1", 1);
		exit(1);
	}
}

void	send_len(pid_t server_pid, unsigned int len)
{
	send_8bit(server_pid, (char)len);
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
		pause();
	}
}

void	send_msg(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_8bit(server_pid, str[i++]);
	send_8bit(server_pid, '\0');
}

void	receive_acknowledgement(int sig, siginfo_t *info, void *ucontent)
{
	(void)ucontent;
	(void)info;
	if (sig == SIGUSR1)
		ft_putstr_fd("Receipt confirmed by server\n", 1);
	else if (sig == SIGUSR2)
		ft_putstr_fd("End of Transmission\n", 1);
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
	len = ft_strlen(argv[2]);
	sig_act.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sig_act.sa_mask);
	sigaddset(&sig_act.sa_mask, SIGUSR1);
	sigaddset(&sig_act.sa_mask, SIGUSR2);
	sig_act.sa_sigaction = receive_acknowledgement;
	sigaction(SIGUSR1, &sig_act, NULL);
	send_len(server_pid, len);
	send_msg(server_pid, argv[2]);
	exit(0);
}

// ERROR PROTECTIONS TO ADD:

// PID is not a number
// PID is not reachable
//