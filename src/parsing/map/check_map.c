#include "../../../includes/so_long.h"

int valid_chars(t_map *map)
{
    int i;
    int j;
    int k;

    if (!map || !map->map)
        return (-1);
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (map->map[i][j] && j < map->width)
        {
            k = 0;
            while (VALID_CHARS[k])
            {
                if (map->map[i][j] != VALID_CHARS[k])
                    k++;
                else
                    break;
                if (!VALID_CHARS[k])
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}


int check_walls(t_map *map)
{
    int i;
    int j;

    if (!map || !map->map)
        return (-1);
    j = 0;
    while (j < map->width)
    {
        if (map->map[0][j] != WALLS || map->map[map->height - 1][j] != WALLS)
            return (0);
        j++;
    }
    i = 1;
    while (i < map->height - 1) 
    {
        if (map->map[i][0] != WALLS || map->map[i][map->width - 1] != WALLS)
            return (0);
        i++;
    }
    return (1);
}
/* int check_collectibles(t_map *map)
{
    if (!map)
        return (-1);
    
    
} */


void check_format(t_map *map)
{
    if (!map)
        return ;
    if (check_walls(map) != 1)
        ft_putstr_fd("CHECK_FORMAT : WALL error\n", 2);
   /*  if (check_collectibles(map) != 1)
        ft_putstr_fd("CHECK_COLLECTIBLES : COLLECTIBLES error\n", 2); */
    
}
void init_map(char *file, t_data *data)
{
    check_map_name(file);
    get_lines(data, file);
    get_map(file, data);
    int i = valid_chars(&data->map);
    printf("return of valid chars: %d\n", i);
    check_format(&data->map);
    check_open_fds();
    close_fds(0);
}



