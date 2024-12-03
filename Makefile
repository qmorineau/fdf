# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_INC) $(MLX_FLAGS)
MLX_FLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lm -lbsd

# Directories
SRC_DIR = src/mandatory
BONUS_DIR = src/bonus
OBJ_DIR = obj/mandatory
OBJ_BONUS_DIR = obj/bonus
LIBFT_DIR = libft

# Name
NAME = fdf
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = ./libmlx.a

# Header
INC = includes/mandatory
INC_BONUS = includes/bonus
LIBFT_INC = libft/includes
MLX_INC = .

# Source and Object files
SRC_LIST = main.c\
			algorithm/bresenham.c\
			algorithm/x_driving.c\
			algorithm/y_driving.c\
			algorithm/z_driving.c\
			event/destroy_window.c\
			event/key_event.c\
			matrix/projection/orthographic.c\
			matrix/projection/isometric.c\
			matrix/utils_mtx.c\
			matrix/rotate_ft.c\
			matrix/rotate_mtx.c\
			matrix/centering.c\
			matrix/scaling.c\
			utils/free.c\
			utils/map_lst.c\
			utils/error.c\
			utils/parsing.c\
			utils/rendering.c\
			utils/init.c

# Source and Object files BONUS
BONUS_LIST = main_bonus.c\
			algorithm/bresenham_bonus.c\
			algorithm/x_driving_bonus.c\
			algorithm/y_driving_bonus.c\
			algorithm/z_driving_bonus.c\
			colors/colors_bonus.c\
			colors/colors_drive_bonus.c\
			colors/utils_colors_bonus.c\
			colors/colors_map_bonus.c\
			event/destroy_window_bonus.c\
			event/key_event_bonus.c\
			event/mouse_event_bonus.c\
			matrix/projection/projection_bonus.c\
			matrix/projection/orthographic_bonus.c\
			matrix/projection/isometric_bonus.c\
			matrix/projection/stereographic_bonus.c\
			matrix/utils_mtx_bonus.c\
			matrix/transform_bonus.c\
			matrix/rotate_ft_bonus.c\
			matrix/rotate_mtx_bonus.c\
			matrix/centering_bonus.c\
			matrix/scaling_bonus.c\
			utils/free_bonus.c\
			utils/map_lst_bonus.c\
			utils/error_bonus.c\
			utils/translate_bonus.c\
			utils/parsing_bonus.c\
			utils/rendering_bonus.c\
			utils/init_bonus.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_LIST:.c=.o))
SRC_BONUS = $(addprefix $(BONUS_DIR)/,$(BONUS_LIST))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/,$(BONUS_LIST:.c=.o))

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
	@mkdir -p $(OBJ_DIR)/event

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)
	@mkdir -p $(OBJ_BONUS_DIR)/utils
	@mkdir -p $(OBJ_BONUS_DIR)/matrix
	@mkdir -p $(OBJ_BONUS_DIR)/matrix/projection
	@mkdir -p $(OBJ_BONUS_DIR)/algorithm
	@mkdir -p $(OBJ_BONUS_DIR)/colors
	@mkdir -p $(OBJ_BONUS_DIR)/event

# Linking object files
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)
	@echo "$(YELLOW)Exec $(NAME) created.$(RESET)"

# Compiling source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(LIBFT_INC) $(MLX_INC)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
# Compile bonus source files to object files
$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(INC_BONUS) $(LIBFT_INC) $(MLX_INC)
	@$(CC) $(CFLAGS) -I $(INC_BONUS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_FOLDER)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)Fdf: Cleaned object files$(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_FOLDER)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)Fdf: Removed binary files$(RESET)"

re: fclean all

bonus: $(OBJ_BONUS_DIR) $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INC_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)
	@echo "$(YELLOW)BONUS : Exec $(NAME) created.$(RESET)"

test: all
	./$(NAME) "planet_maps/earth.fdf"

.PHONY: all clean fclean re bonus test
