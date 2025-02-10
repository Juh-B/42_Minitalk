SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Werror -Wextra

INLUDES = minitalk.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) server.c -o $(SERVER) $(LIBFT)
	$(CC) $(CFLAGS) client.c -o $(CLIENT) $(LIBFT)
	@echo "Server And Client Are Ready!"

bonus:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) server_bonus.c -o $(SERVER) $(LIBFT)
	$(CC) $(CFLAGS) client_bonus.c -o $(CLIENT) $(LIBFT)
	@echo "Server And Client Are Ready! - Bonus"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean bonus all

.PHONY: all bonus clean fclean re