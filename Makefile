# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_INC) -fsanitize=address -g
MLX_FLAGS = -lX11 -lXext -lXrandr -lXrender -lXfixes -lm -lbsd

# Directories
SRC_DIR = src/mandatory
BONUS_DIR = src/bonus
OBJ_DIR = obj/mandatory
OBJ_BONUS_DIR = obj/bonus
OBJ_FOLDER = obj
LIBFT_DIR = libft

# Name
NAME = fdf
NAME_BONUS = fdf_bonus
LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = minilibx-linux/libmlx.a

# Header
INC = includes/mandatory
INC_BONUS = includes/bonus
LIBFT_INC = libft/includes
MLX_INC = minilibx-linux

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
			utils/init.c\
			utils/is_fdf_file.c

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
			utils/init_bonus.c\
			utils/is_fdf_file_bonus.c

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
$(NAME): $(MLX_LIB) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS)
	@echo "$(YELLOW)Exec $(NAME) created.$(RESET)"

# Compiling source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(LIBFT_INC) $(MLX_INC)
	@$(CC) $(CFLAGS) -I $(INC) -I $(MLX_INC) -c $< -o $@
# Compile bonus source files to object files
$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(INC_BONUS) $(LIBFT_INC) $(MLX_INC)
	@$(CC) $(CFLAGS) -I $(INC_BONUS) -I $(MLX_INC) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX_LIB):
	@make -C $(MLX_INC) --no-print-directory

clean:
	@rm -rf $(OBJ_FOLDER)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_INC) --no-print-directory
	@echo "$(RED)Fdf: Cleaned object files$(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -rf $(OBJ_FOLDER)
	@rm -rf minilibx-linux/obj
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "$(RED)Fdf: Removed binary files$(RESET)"

re: fclean all

bonus: $(OBJ_BONUS_DIR) $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS) $(MLX_LIB)
	@$(CC) $(CFLAGS) -I $(INC_BONUS) $(OBJ_BONUS) $(LIBFT) $(MLX_LIB) -o $(NAME_BONUS) $(MLX_FLAGS)
	@echo "$(YELLOW)BONUS : Exec $(NAME) created.$(RESET)"

norm:
	@norminette includes
	@norminette libft
	@norminette src

.PHONY: all clean fclean re bonus norm
