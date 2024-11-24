# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_INC) $(MLX_FLAGS)
MLX_FLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lm -lbsd

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Name
NAME = fdf
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = ./libmlx.a
# MLX_LIB = /usr/local/lib/libmlx.a

# Header
INC = includes
LIBFT_INC = libft/includes
MLX_INC = .
#MLX_INC = /usr/local/include

# Source and Object files
SRC_LIST = main.c\
			matrix/utils_mtx.c\
			matrix/projection/projection.c\
			matrix/projection/orthographic.c\
			matrix/projection/isometric.c\
			matrix/projection/stereographic.c\
			matrix/transform.c\
			matrix/rotate_ft.c\
			matrix/rotate_mtx.c\
			matrix/centering.c\
			matrix/scaling.c\
			matrix/translating.c\
			algorithm/bresenham.c\
			event/destroy_window.c\
			event/key_event.c\
			event/mouse_event.c\
			colors/colors.c\
			utils/free.c\
			utils/map_lst.c\
			utils/error.c\
			parsing.c\
			rendering.c\
			init.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_LIST:.c=.o))

# Colors
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# Main
all: $(OBJ_DIR) $(NAME)

# Create path for object
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/matrix
	@mkdir -p $(OBJ_DIR)/matrix/projection
	@mkdir -p $(OBJ_DIR)/algorithm
	@mkdir -p $(OBJ_DIR)/colors
	@mkdir -p $(OBJ_DIR)/event

# Linking object files
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)
	@echo "$(YELLOW)Exec $(NAME) created.$(RESET)"

# Compiling source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(LIBFT_INC) $(MLX_INC)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)Fdf: Cleaned object files$(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)Fdf: Removed binary files$(RESET)"

re: fclean all

test: all
	./$(NAME) "test_maps/42.fdf"

leak: all
	-valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "test_maps/42.fdf"

.PHONY: all clean fclean re test
