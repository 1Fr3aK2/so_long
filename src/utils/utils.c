#include "../../includes/so_long.h"

// funcao criada pelo user para colocar pixeis na janela
/* static void my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data)
		return ;
	dst = data->image.addr + (y * data->image.line_length + x
			* (data->image.bits_per_pixel/8));
	*(unsigned int *)dst = color;
} */
/* void init(t_data *data)
{
	ft_calloc(1, sizeof(t_data));
	data->image.img =
} */
void	close_fds(int i)
{
	i = 3;
	while (i < FOPEN_MAX)
	{
		close(i);
		i++;
	}
}

void	check_open_fds(void)
{
	int	fd;
	// F_GETFD retorna -1 se o FD não está em uso

	for (fd = 3; fd < 1024; ++fd)
	{
		if (fcntl(fd, F_GETFD) != -1)
		{
			printf("\nFD %d is still open\n", fd);
		}
	}
}

void	free_arr(char **arr, int height)
{
	int	i;
	
	if (!arr)
		return ;
	i = 0;
	while (i < height && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void *my_malloc(size_t size) 
{
	int malloc_fail_counter = 0;  // Número de chamadas antes de falhar
    if (--malloc_fail_counter <= 0) {
        return NULL;  // Força falha de alocação
    }
    return malloc(size);
}