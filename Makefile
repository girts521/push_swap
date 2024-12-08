NAME = push_swap
FT_PRINTF_DIR = ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -I$(FT_PRINTF_DIR)/includes

SRCS = main.c error.c instructions.c utils.c sort_small.c radix_sort.c quick_sort.c

OBJS  :=  $(SRCS:.c=.o)

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF_DIR) -lftprintf -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
