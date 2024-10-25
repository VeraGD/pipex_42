
NAME = pipex

SRC = ft_aux_hexa.c ft_aux_printf.c ft_printf.c ft_split.c \
pipex_free.c pipex_utils.c pipex_path.c pipex_fork.c main_pipex.c

INCLUDE = pipex.h

OBJT = $(SRC:.c=.o)

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all:		$(NAME)

$(NAME):	$(OBJT) $(INCLUDE)
		cc -Wall -Werror -Wextra $(OBJT) -o $(NAME)
		@echo "${GREEN}Pipex compilation OK${RESET}"

clean:
		-rm -f $(OBJT)
		@echo "${YELLOW}All objects removed${RESET}"

fclean: 	clean
		-rm -f $(NAME)
		@echo "${RED}Pipex removed${RESET}"

re:			fclean all

.PHONY: all clean fclean re