#include "minitalk.h"

static int	msg_received = 0;

static void	wait_signal(int signal)
{
	if (signal == SIGUSR1)
		msg_received = 1;
}

static void	send_message(unsigned int server_pid, char *message, int len)
{
	int		bits;
	int		char_index;

	char_index = 0;
	while (char_index < len)
	{
		bits = 0;
		while (bits < 8)
		{
			if ((message[char_index] >> (7 - bits)) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			bits++;
			usleep(1000);
			while (msg_received == 0)
				pause();
			msg_received = 0;
		}
		char_index++;
	}
}

int	main(int argc, char **argv)
{
	unsigned int	server_pid;

	if (argc != 3)
	{
		ft_printf("Please, send your mensage with this format:\n");
		ft_printf("%s PID_number 'Your_mensage'\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid PID.\n");
		return (1);
	}
	signal(SIGUSR1, wait_signal);
  ft_printf("Mensage received.\n");
	send_message(server_pid, argv[2], ft_strlen(argv[2]) + 1);
	return (0);
}

