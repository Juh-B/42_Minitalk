# Project name
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(CFLAGS) server.c -o $(SERVER) $(LIBFT)
	$(CC) $(CFLAGS) client.c -o $(CLIENT) $(LIBFT)
	@echo "Server And Client Are Ready!"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all

.PHONY: all clean fclean re
