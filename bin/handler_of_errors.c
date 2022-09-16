#include "../lib/include/cub3D.h"

void	handler_errors(int number_of_error)
{
	if (number_of_error == 1)
	{
		printf("%s\n", "Wrong count of param's!!!");
		exit(1);
	}
	if (number_of_error == 2)
	{
		perror("Open map file ERROR");
		exit(1);
	}
	if (number_of_error == 3)
	{
		printf("%s\n", "Map file not *.cub!!!");
		exit(1);
	}
	if (number_of_error == 4)
	{
		perror("Malloc ERROR");
		exit(1);
	}
	if (number_of_error == 5)
	{
		printf("%s\n", "Map file empty");
		exit(1);
	}
}

void	handler_errors_of_map(char *string_of_error, t_info *info)
{
	int	line;

	line = 0;
	while (info->map[line])
	{
		free(info->map[line]);
		line++;
	}
	free(info->map);
	printf("%s\n", string_of_error);
	exit(1);
}
