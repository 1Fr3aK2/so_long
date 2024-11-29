#include "../../../../includes/so_long.h"

int	check_valid_map(t_map *map, t_data *data)
{
	if (!map || !data)
		return (-1);
	if (check_format(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/RECTANGULAR: RECTANGULAR ERROR\n");
	if (valid_chars(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/CHARS: CHARS ERROR\n");
	if (check_walls(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/WALLS: WALL ERROR\n");
	if (check_exit(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/EXIT: EXIT ERROR\n");
	if (check_collectibles(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/COLLECt: COLLECTIBLES ERROR\n");
	if (check_start_pos(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/START_POS: START_POS ERROR\n");
	return (1);
}
