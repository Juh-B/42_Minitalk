#include "minitalk.h"

static t_message	msg_received = {0, 0};

static void	ft_assemble_msg(void)
{
	char	*updated_msg;
	char	c;

	updated_msg = NULL;
	c = (char)msg_received.c;
	if (msg_received.msg != NULL)
	{
		updated_msg = ft_strjoin(msg_received.msg, &c);
		free(msg_received.msg);
	}
	else
		updated_msg = ft_strdup(&c);
	if (updated_msg == NULL)
		exit(EXIT_FAILURE);
	msg_received.msg = updated_msg;
}

static void	ft_print_message(void)
{
	if (msg_received.c == '\0')
	{
		if (msg_received.msg != NULL)
			ft_printf("%s\n", msg_received.msg);
		else
			ft_printf("\n");
		free(msg_received.msg);
		msg_received.msg = NULL;
	}
	else
		ft_assemble_msg();
	msg_received.c = 0;
}

static void	ft_handle_binary(int signal, siginfo_t *info, void *context)
{
	static int	bits = 0;

	(void)context;
	if (signal == SIGUSR1)
		msg_received.c = (msg_received.c << 1) | 1;
	else if (signal == SIGUSR2)
		msg_received.c = (msg_received.c << 1);
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
	{
		pause();
	}
	return (0);
}

