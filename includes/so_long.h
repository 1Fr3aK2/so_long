#ifndef SO_LONG_H
# define SO_LONG_H

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

# define VALID_CHARS "01CEP"
# define WALLS '1'
# define SPACE '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START_POS 'P'

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../includes/libft/libft.h"
# include "../includes/libft/ft_printf/ft_printf.h"
# include "../includes/libft/get_next_line/get_next_line_bonus.h"
# include "../includes/minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		collectibles;
	int		start_pos;
	int		exit;
}				t_map;

typedef struct s_file
{
	int			fd;
	char		*file_name;
}				t_file;

/* typedef struct s_arr
{
	s_map char	**map;
}				t_arr; */

typedef struct s_data
{
	t_image	image;
	t_map	map;
	t_file	file;
}				t_data;

//parsing/file
void	check_map_name(char *file_name);
void	get_lines(t_data *data, char *file_name);
void	get_map(char *file_name, t_data *data);

//parsing/map
int		valid_chars(t_map *map);
int		check_walls(t_map *map);
int		check_collectibles(t_map *map);
int		check_start_pos(t_map *map);
int		check_exit(t_map *map);
void	check_format(t_map *map, t_data *data);
void	init_map(char *file, t_data *data);

//parsing/struct_init
void	init_struct(t_data *data);

//errors
void	exit_error(t_data *data);

//utils 
void	close_fds(int i);
void	check_open_fds(void);
void	free_arr(char **arr);
#endif