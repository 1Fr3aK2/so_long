#include "../../includes/so_long.h"

void	close_fds(int i)
{
	i = 3;
	while (i < FOPEN_MAX)
	{
		close(i);
		i++;
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
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_temp_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	*my_malloc(size_t size)
{
	int malloc_fail_counter = 0; // Número de chamadas antes de falhar
	if (--malloc_fail_counter <= 0)
	{
		return (NULL); // Força falha de alocação
	}
	return (malloc(size));
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
