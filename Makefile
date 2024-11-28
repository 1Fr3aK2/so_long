SRCS = main/main.c \
       src/parsing/file/check_file.c \
	   src/parsing/map/check_map/check_map.c  \
	   src/parsing/map/check_map/check_map_utils.c  \
	   src/parsing/map/check_map/check_map_utils2.c  \
	   src/parsing/map/check_temp_map/check_temp_map.c	\
	   src/parsing/map/get_map/get_map.c \
	   src/parsing/map/init_map.c \
	   src/init/init.c \
	   src/utils/utils.c \
	   src/utils/utils_2.c \
	   src/errors/errors.c \
	   src/game/init_game.c \
	   src/game/images/load_images.c \
	   src/game/animations/load_animations.c \
	   src/game/keys/handle_keys.c \
	   src/game/draw/draw.c \

NAME = so_long

COMPRESS = ar rcs	

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

# Lista de arquivos .o correspondentes aos .c
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTFDIR = ./libraries/libft/ft_printf
FT_PRINT = $(FT_PRINTFDIR)/libftprintf.a

GNL_DIR = ./libraries/libft/get_next_line
GNL = $(GNL_DIR)/get_next_line

MLX_DIR = ./libraries/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# Adiciona as flags para o MinilibX e as bibliotecas de X11
LINKS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

all: $(NAME) $(LIBFT) $(FT_PRINT) $(GNL) $(MLX)

# Regra para criar o executável a partir dos arquivos objeto e bibliotecas
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINT) $(GNL) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINT) $(GNL) $(MLX) $(LINKS)
	@echo $(NAME) ready!

# Regra para compilar arquivos objeto a partir de arquivos fonte, cria a pasta para o arq obj se nao existir
$(OBJ_DIR)/%.o: src/%.c | $(CREATE_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CREATE_DIR):
	@mkdir -p $(OBJ_DIR)/errors
	@mkdir -p $(OBJ_DIR)/main
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/parsing/file
	@mkdir -p $(OBJ_DIR)/parsing/map
	@mkdir -p $(OBJ_DIR)init
	@mkdir -p $(OBJ_DIR)/utils

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINT):
	@$(MAKE) -C $(FT_PRINTFDIR) --no-print-directory

$(GNL):
	@$(MAKE) -C $(GNL_DIR) --no-print-directory

$(MLX):
	@$(MAKE) -C $(MLX_DIR) # Compila o MinilibX

clean:
	@$(RM) -r $(OBJ_DIR)  # Remove o diretório obj e seu conteúdo
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory  # Limpa os arquivos da biblioteca libft
	@$(MAKE) -C $(FT_PRINTFDIR) clean --no-print-directory  # Limpa os arquivos da biblioteca ft_printf
	@$(MAKE) -C $(GNL_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory  # Limpa os arquivos da biblioteca MinilibX

fclean: clean
	@$(RM) $(NAME)  # Remove o executável
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) fclean --no-print-directory
	@$(MAKE) -C $(GNL_DIR) fclean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
