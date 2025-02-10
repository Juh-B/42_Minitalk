/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:30:15 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/02/10 11:10:35 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_msg = {0, 0};

static void	ft_assemble_msg(void)
{
	char	*updated_msg;
	char	c;

	updated_msg = NULL;
	c = (char)g_msg.c;
	if (g_msg.msg != NULL)
	{
		updated_msg = ft_strjoin(g_msg.msg, &c);
		free(g_msg.msg);
	}
	else
		updated_msg = ft_strdup(&c);
	if (updated_msg == NULL)
		exit(EXIT_FAILURE);
	g_msg.msg = updated_msg;
}

static void	ft_print_message(void)
{
	if (g_msg.c == '\0')
	{
		if (g_msg.msg != NULL)
			ft_printf("%s\n", g_msg.msg);
		else
			ft_printf("\n");
		free(g_msg.msg);
		g_msg.msg = NULL;
	}
	else
		ft_assemble_msg();
	g_msg.c = 0;
}

static void	ft_handle_binary(int signal, siginfo_t *info, void *context)
{
	static int	bits = 0;

	(void)context;
	if (signal == SIGUSR1)
		g_msg.c = (g_msg.c << 1) | 1;
	else if (signal == SIGUSR2)
		g_msg.c = (g_msg.c << 1);
	bits++;
	if (bits == 8)
	{
		ft_print_message();
		bits = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome to Minitalk Server!\n--- PID: %d ---\n", getpid());
	sa.sa_sigaction = ft_handle_binary;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
