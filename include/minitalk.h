/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:29 by mstrauss          #+#    #+#             */
/*   Updated: 2024/04/20 15:32:44 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef WAHR
#  define WAHR 1
# endif

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

/* --------------------------------- CLIENT --------------------------------- */
void	w_kill(pid_t pid, int i);
void	send_len(pid_t server_pid, unsigned int len);
void	send_8bit(pid_t server_pid, int b);
void	send_msg(pid_t server_pid, char *str);
void	receive_acknowledgement(int sig, siginfo_t *info, void *ucontent);

/* --------------------------------- SERVER --------------------------------- */
void	receive_8bits(int sig, siginfo_t *info, void *ucontent);
void	print_and_reset(char **str, int *str_ind, unsigned int len);
#endif
