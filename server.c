#include "./libft/libft.h"
#include <signal.h>

void handle_signal(int signal)
{
  static char  signal_char;
  static int bits;

  if (signal == SIGUSR2)
    signal_char |= (1 << bits);
  bits++;
  if (bits == 8)
  {
    write(1, &signal_char, 1);
    signal_char = 0;
    bits = 0;
  }
}

int main(void)
{
  ft_printf("Welcome to Minitalk Server!\n");
  ft_printf("--- PID: %d ---\n", getpid());

  signal(SIGUSR1, handle_signal);
  signal(SIGUSR2, handle_signal);
  while (1)
    pause();
  return (0);
}
