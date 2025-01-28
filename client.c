#include "./libft/libft.h"
#include <signal.h>

void  send_char(int server_pid, char c)
{
  int bits;

  bits = 0;
  while (bits < 8)
  {
    if ((c >> bits) & 1)
      kill(server_pid, SIGUSR2);
    else
      kill(server_pid, SIGUSR1);
    bits++;
    usleep(300);
  }
}

int main(int argc, char **argv)
{
  int server_pid;
  char  *mensage;
  int i;

  if (argc != 3)
  {
    ft_printf("Please, send your mensage with this format:\n");
    ft_printf("%s PID_number 'Your_mensage'\n", argv[0]);
    return (1);
  }
  server_pid = ft_atoi(argv[1]);
  mensage = argv[2];
  i = 0;
  while (mensage[i])
  {
    send_char(server_pid, mensage[i]);
    i++;
  }
  send_char(server_pid, '\n');
  return (0);
}
