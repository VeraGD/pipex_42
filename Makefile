
NAME = pipex

SRC = ft_aux_hexa.c ft_aux_printf.c ft_printf.c ft_split.c \
pipex_free.c pipex_utils.c pipex_path.c pipex_fork.c main_pipex.c

SRC_B = ft_aux_hexa.c ft_aux_printf.c ft_printf.c ft_split.c \
pipex_free.c pipex_utils.c pipex_utils_bonus.c pipex_path.c \
pipex_ini_bonus.c pipex_choose_bonus.c pipex_fork_bonus.c \
main_pipex_bonus.c

INCLUDE = pipex.h

OBJT = $(SRC:.c=.o)
OBJT_B = $(SRC_B:.c=.o)

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all:		$(NAME)

$(NAME):	$(OBJT) $(INCLUDE)
		cc -Wall -Werror -Wextra -g $(OBJT) -o $(NAME)
		@echo "${GREEN}Pipex compilation OK${RESET}"

bonus:		$(OBJT_B) $(INCLUDE)
		cc -Wall -Werror -Wextra -g $(OBJT_B) -o $(NAME)
		@echo "${GREEN}Pipex bonus compilation OK${RESET}"

clean:
		-rm -f $(OBJT) $(OBJT_B)
		@echo "${YELLOW}All objects removed${RESET}"

fclean: 	clean
		-rm -f $(NAME)
		@echo "${RED}Pipex removed${RESET}"

re:			fclean all

.PHONY: all clean fclean re