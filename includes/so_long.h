#ifndef SO_LONG_H
#define SO_LONG_H


#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF
#define BLACK 0x00000000


#include <unistd.h>
#include <stdio.h>
# include "../includes/libft/libft.h"
# include "../includes/libft/ft_printf/ft_printf.h"
#include    "../includes/minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//parsing
int check_name(char *name);


#endif