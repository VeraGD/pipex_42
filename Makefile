
NAME = pipex

SRC = src/printf/ft_aux_hexa.c src/printf/ft_aux_printf.c src/printf/ft_printf.c \
src/utils/ft_split.c src/utils/pipex_free.c src/utils/pipex_utils.c \
src/pipex/pipex_path.c src/pipex/pipex_fork.c src/main/main_pipex.c

SRC_B = src/printf/ft_aux_hexa.c src/printf/ft_aux_printf.c src/printf/ft_printf.c \
src/utils/ft_split.c src/utils/pipex_free.c src/utils/pipex_utils.c \
src/utils/pipex_utils_bonus.c src/pipex/pipex_path.c src/pipex/pipex_ini_bonus.c \
src/pipex/pipex_choose_bonus.c src/pipex/pipex_fork_bonus.c \
src/main/main_pipex_bonus.c

INCLUDE = pipex.h

OBJT = $(SRC:.c=.o)
OBJT_B = $(SRC_B:.c=.o)

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all:		$(NAME)

$(NAME):	$(OBJT) $(INCLUDE)
		cc -Wall -Werror -Wextra $(OBJT) -o $(NAME)
		@echo "${GREEN}Pipex compilation OK${RESET}"

bonus:		$(OBJT_B) $(INCLUDE)
		cc -Wall -Werror -Wextra $(OBJT_B) -o $(NAME)
		@echo "${GREEN}Pipex bonus compilation OK${RESET}"

clean:
		-rm -f $(OBJT) $(OBJT_B)
		@echo "${YELLOW}All objects removed${RESET}"

fclean: 	clean
		-rm -f $(NAME)
		@echo "${RED}Pipex removed${RESET}"

re:			fclean all

.PHONY: all clean fclean re