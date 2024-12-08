#include "../../../includes/so_long.h"

void	check_map_name(char *file_name)
{
	t_file	file;
	int		len;

	if (!file_name)
		exit_error(NULL, "ERROR:\nCHECK_MAP : Invalid pointer to file name\n");
	file.fd = open(file_name, O_RDONLY);
	if (file.fd < 0)
		exit_error(NULL, "ERROR:\nCHECK_MAP : Error opening the file\n");
	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(&file_name[len - 4], ".ber", 4) != 0)
		exit_error(NULL, "ERROR:\n: Invalid map name, should be .ber\n");
	close(file.fd);
}
