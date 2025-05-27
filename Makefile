CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc
NAME = push_swap
NAME_BONUS = checker
A_C = ar rcs

LIBFT = ./src/libft
GNL = ./bonus/get_next_line
SRC = ./src
BONUS = ./bonus

FILES_MINE = \
			$(LIBFT)/ft_atoi.c $(LIBFT)/ft_atol.c $(LIBFT)/ft_strlen.c \
			$(LIBFT)/ft_isdigit.c $(LIBFT)/ft_isspace.c $(LIBFT)/ft_strcmp.c \
			$(LIBFT)/ft_sqrt.c $(LIBFT)/ft_split.c $(LIBFT)/ft_substr.c \
			$(LIBFT)/ft_strdup.c $(LIBFT)/ft_atol_push.c
FILES_GNL = \
			$(GNL)/get_next_line_utils.c $(GNL)/get_next_line.c
FILES = \
		$(SRC)/stack_utils_1.c $(SRC)/stack_utils_2.c $(SRC)/stack_utils_3.c \
		$(SRC)/push_swap.c $(SRC)/operations_1.c $(SRC)/operations_2.c \
		$(SRC)/sort.c $(SRC)/sort_utils.c $(SRC)/sort_specific.c \
		$(SRC)/control_argc.c $(SRC)/control_argv.c
FILES_BONUS = \
			$(BONUS)/stack_utils_1_bonus.c $(BONUS)/stack_utils_2_bonus.c $(BONUS)/checker_bonus.c \
			$(BONUS)/operations_1_bonus.c $(BONUS)/operations_2_bonus.c $(BONUS)/control_argc_bonus.c \
			$(BONUS)/control_argv_bonus.c $(BONUS)/checker_functions_bonus.c

OBJS_MINE = $(FILES_MINE:.c=.o)
OBJS_GNL = $(FILES_GNL:.c=.o)
OBJS = $(FILES:.c=.o)
OBJS_BONUS = $(FILES_BONUS:.c=.o)

%.o: %.c
	@echo "🔧Compiling $< 🔨"
	@$(CC) $(CFLAGS) -c $< -o $@


all: show_name $(NAME)

$(NAME): $(OBJS_MINE) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS_MINE) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Created $(NAME) ✓$(RESET)"

bonus: show_name_bonus .bonus

.bonus: $(OBJS_MINE) $(OBJS_GNL) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_MINE) $(OBJS_GNL) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)Created $(NAME_BONUS) ✓$(RESET)"
	@touch .bonus

clean:
	@rm -rf $(OBJS) $(OBJS_MINE)
	@echo "$(RED)Objects Removed ✓$(RESET)"

clean_bonus:
	@rm -rf $(OBJS_BONUS) $(OBJS_GNL)
	@echo "$(RED)Objects Bonus Removed ✓$(RESET)"

fclean: clean clean_bonus
	@rm -f $(NAME) $(NAME_BONUS) .bonus
	@echo "$(RED)$(NAME) Removed ✓$(RESET)"
	@echo "$(RED)$(NAME_BONUS) Removed ✓$(RESET)"

re: fclean all


GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

show_name_bonus:
	@echo "$(BLUE)==================================================$(RESET)"
	@echo "$(YELLOW)[........[.......          [.       [...     [.."
	@echo "[..      [..    [..       [. ..     [. [..   [.."
	@echo "[..      [..    [..      [.  [..    [.. [..  [.."
	@echo "[......  [. [..         [..   [..   [..  [.. [.."
	@echo "[..      [..  [..      [...... [..  [..   [. [.."
	@echo "[..      [..    [..   [..       [.. [..    [. .."
	@echo "[..      [..      [..[..         [..[..      [..$(RESET)"
	@echo "$(BLUE)==================================================$(RESET)"
	@echo "$(GREEN)Compiling push_swap bonus...$(RESET)"

show_name:
	@echo "$(BLUE)==================================================$(RESET)"
	@echo "$(YELLOW)[........[.......          [.       [...     [.."
	@echo "[..      [..    [..       [. ..     [. [..   [.."
	@echo "[..      [..    [..      [.  [..    [.. [..  [.."
	@echo "[......  [. [..         [..   [..   [..  [.. [.."
	@echo "[..      [..  [..      [...... [..  [..   [. [.."
	@echo "[..      [..    [..   [..       [.. [..    [. .."
	@echo "[..      [..      [..[..         [..[..      [..$(RESET)"
	@echo "$(BLUE)==================================================$(RESET)"
	@echo "$(GREEN)Compiling push_swap...$(RESET)"

.PHONY: all clean fclean re bonus show_name show_name_bonus