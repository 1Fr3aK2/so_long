#include "../../includes/so_long.h"

void exit_error(t_data *data, char *str)
{
    if (str)
        ft_putstr_fd(str, 2);
    else
        ft_putstr_fd("Error\n", 2);
    free_images(data);
    if (data)
    {
        if (data->map.map) 
        {
            free_arr(data->map.map, data->map.height);  // Libera o mapa, se não for nulo
            data->map.map = NULL;  // Evita acessos futuros
        }
        if (data->window_ptr)
        {
            mlx_destroy_window(data->mlx_ptr, data->window_ptr);  // Destrói a janela, se houver
            data->window_ptr = NULL;
        }
        if (data->mlx_ptr)
        {
            mlx_destroy_display(data->mlx_ptr);  // Libera o display
            free(data->mlx_ptr);
            data->mlx_ptr = NULL;
        }
        /* free(data); */  // Libera a estrutura de dados
        data = NULL;
    }
    close_fds(0);  // Fecha os descritores de arquivos abertos
    check_open_fds();  // Verifica se há descritores de arquivos abertos
    exit(1);  // Sai com código de erro
}

void free_images(t_data *data)
{
    if (!data)
        return ;
    else
    {
        if (data->sprites.wall.img)
            mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img);
        if (data->sprites.floor.img)
            mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
        if (data->sprites.exit.img)
            mlx_destroy_image(data->mlx_ptr, data->sprites.exit.img);
        if (data->sprites.collectibles.img)
            mlx_destroy_image(data->mlx_ptr, data->sprites.collectibles.img);
    }
}

/* void	exit_error(t_data *data, char *str)
{
	int	freed;

	if (!str)
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	freed = 0;
	if (data && data->map.map)
	{
		free_arr(data->map.map, data->map.height);
		freed = 1;
	}
	if (data && data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->window_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	if (data && freed == 0)
		free(data);
	close_fds(0);
	check_open_fds();
	exit(1);
} */

