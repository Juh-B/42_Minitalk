/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:31:15 by jcosta-b          #+#    #+#             */
/*   Updated: 2025/01/31 18:51:55 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>
# include <stdbool.h>

static bool	msg_received = false;

void	handle_signal(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
		msg_received = true;	
}

void	send_char(int server_pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		msg_received = false;
		if ((c >> bits) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (!msg_received)
			;
		bits++;
		// usleep(5000);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*mensage;
	int		i;

	if (argc != 3)
	{
		ft_printf("Please, send your mensage with this format:\n");
		ft_printf("%s PID_number 'Your_mensage'\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	mensage = argv[2];
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	i = 0;
	while (mensage[i])
	{
		send_char(server_pid, mensage[i]);
		i++;
	}
	send_char(server_pid, '\n');
	return (0);
}
