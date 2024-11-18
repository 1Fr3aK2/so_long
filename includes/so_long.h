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
# include "../libraries/libft/libft.h"
# include "../libraries/libft/ft_printf/ft_printf.h"
# include "../libraries/libft/get_next_line/get_next_line_bonus.h"
# include "../libraries/minilibx-linux/mlx.h"
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
	int		check_coll;
	int		start_pos;
	int		exit;
	int		check_exit;
	int		exit_x;
	int		exit_y;
}				t_map;

typedef struct s_file
{
	int			fd;
	char		*file_name;
}				t_file;

typedef struct s_player
{
	int			x;
	int			y;

}				t_player;

typedef struct s_data
{
	t_image		image;
	t_map		map;
	t_file		file;
	t_player	player;
	void		*mlx_ptr;
	int			screen_size;
	int			screen_width;
	void		*window_ptr;
}				t_data;

//errors
void	exit_error(t_data *data, char *str);

//game
void    init_game(t_data *data);

//init
void	init_struct(t_data *data);

//parsing/file
void	check_map_name(char *file_name);

//parsing/check_map/check_map
void	check_valid_map(t_map *map, t_data *data);

//parsing/check_map/check_map_utils
int		check_format(t_map *map);
int		valid_chars(t_map *map);
int		check_walls(t_map *map);
int		check_collectibles(t_map *map);
int		check_exit(t_map *map);
int		check_start_pos(t_map *map);
void	get_positions(t_map *map, t_data *data);

//parsing/check_map/check_temp_map
char	**copy_map(char **map, int height);
void	flood_fill_map(char **map, int y, int x, t_data *data);
void	check_flood_fill(char **map, t_data *data);
int		check_valid_path(t_map *map, t_data *data);

//parsing/get_map
void	get_lines(t_data *data, char *file_name);
void	get_map(char *file_name, t_data *data);

//parsing/init_map
void	init_map(char *file, t_data *data);

//utils 
void	close_fds(int i);
void	free_arr(char **arr, int height);
void	free_temp_map(char **map);


//test_functions
void	check_open_fds(void);
void	*my_malloc(size_t size);
#endif