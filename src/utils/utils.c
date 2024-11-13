
#include "../../includes/so_long.h"

//funcao criada pelo user para colocar pixeis na janela
/* static void my_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    if (!data)
        return ;
    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel/8));
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

void check_open_fds()
{
    int fd;
    for (fd = 3; fd < 1024; ++fd) // Começa no 3 porque 0, 1, e 2 são stdin, stdout, stderr
    {
        if (fcntl(fd, F_GETFD) != -1) // F_GETFD retorna -1 se o FD não está em uso
        {
            printf("\nFD %d is still open\n", fd);
        }
    }
}

/* void	ft_free(char **cmd)
{
	size_t	i;

	if (!(*cmd) || !cmd)
		return ;
	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
} */