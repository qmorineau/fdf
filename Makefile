# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_INC) $(MLX_FLAGS) -fsanitize=address -g
MLX_FLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lm -lbsd

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

# Name
NAME = fdf
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = /usr/local/lib/libmlx.a

# Header
INC = includes
LIBFT_INC = libft/includes
MLX_INC = /usr/local/include

# Source and Object files
SRC_LIST = main.c\
			matrix/center_mtx.c\
			matrix/utils_mtx.c\
			matrix/projection.c\
			matrix/proj_orthographic.c\
			matrix/proj_isometric.c\
			matrix/proj_stereographic.c\
			matrix/rotate_ft.c\
			matrix/rotate_mtx.c\
			matrix/scale_mtx.c\
			matrix/translate_mtx.c\
			algorithm/bresenham.c\
			utils/free.c\
			utils/map_lst.c\
			parsing.c\
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
	@mkdir -p $(OBJ_DIR)/algorithm
	@mkdir -p $(OBJ_DIR)/projection

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
	@echo "$(RED)Push_swap: Cleaned object files$(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)Push_swap: Removed binary files$(RESET)"

re: fclean all

test: all
	./$(NAME) "map.txt"

.PHONY: all clean fclean re test
