SRCS = src/main/main.c \
       src/parsing/check_file.c \

NAME = so_long

COMPRESS = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra #-Werror

OBJ_DIR = obj

# Lista de arquivos .o correspondentes aos .c
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTFDIR = ./includes/libft/ft_printf
FT_PRINT = $(FT_PRINTFDIR)/libftprintf.a

MLX_DIR = ./includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# Adiciona as flags para o MinilibX e as bibliotecas de X11
LINKS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

all: $(NAME)

# Regra para criar o executável a partir dos arquivos objeto e bibliotecas
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINT)
	@$(MAKE) -C $(MLX_DIR) # Compila o MinilibX
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINT) $(LINKS)
	@echo $(NAME) ready!

# Regra para compilar arquivos objeto a partir de arquivos fonte, cria a pasta para o arq obj se nao existir
$(OBJ_DIR)/%.o: src/%.c | $(CREATE_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CREATE_DIR):
	@mkdir -p $(OBJ_DIR)/main
	@mkdir -p $(OBJ_DIR)/parsing

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(FT_PRINT):
	@$(MAKE) -C $(FT_PRINTFDIR) --no-print-directory

clean:
	@$(RM) -r $(OBJ_DIR)  # Remove o diretório obj e seu conteúdo
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory  # Limpa os arquivos da biblioteca libft
	@$(MAKE) -C $(FT_PRINTFDIR) clean --no-print-directory  # Limpa os arquivos da biblioteca ft_printf
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory  # Limpa os arquivos da biblioteca MinilibX

fclean: clean
	@$(RM) $(NAME)  # Remove o executável
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTFDIR) fclean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
