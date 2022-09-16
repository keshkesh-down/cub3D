#include "../lib/include/cub3D.h"

int	ext_of_map(char *argv)
{
	int		i;
	int		j;
	char	*str_ext_of_map;

	j = 0;
	str_ext_of_map = ".cub";
	i = ft_strlen(argv) - 4;
	while (argv[i])
	{
		if (argv[i] != str_ext_of_map[j] || !str_ext_of_map[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	get_count_of_line(char *filepath)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		handler_errors(2);
	height = 8;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++height;
	}
	free(line);
	close (fd);
	return (height);
}

void	read_map(char *filepath, t_info *info) //  todo: сделать обработку букв вест и т.п. а также добавить пропуск переноса строки
{
	int		fd;
	int		rd;
	int		height;

	info->height = get_count_of_line(filepath);
	if (info->height == 7 || info->height == 8)
		handler_errors(5);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		handler_errors(2);
	rd = fd;
	info->map = (char **)malloc(sizeof(char *) * (info->height + 1));
	if (info->map == NULL)
		handler_errors(4);
	height = 8;
	while (height < info->height)
	{
		info->map[height] = get_next_line(fd);
		height++;
	}
	info->map[height] = 0;
	close(fd);
}

void	check_chars_of_map(t_info *info, int *player, int *exits) //todo: добавить обработку енеми и т.п.
{
	int	l;
	int	c;

	l = 0;
	*player = 0;
	*exits = 0;
	while (l < info->height)
	{
		c = 0;
		while (c < info->width)
		{
			if (info->map[l][c] == 'N' || info->map[l][c] == 'W' || info->map[l][c] == 'E' || info->map[l][c] == 'S')
				++*player;
			else if (info->map[l][c] != '1' && info->map[l][c] != '0')
				handler_errors_of_map("Map have \"garbage\" simbols!!!", info);
			c++;
		}
		l++;
	}
}

void	check_walls(t_info *info)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	while (line < info->height)
	{
		if (line == 0 || line == info->height - 1)
		{
			column = 0;
			while (info->map[line][column] != '\n' && info->map[line][column])
			{
				if (info->map[line][column] != '1')
					handler_errors_of_map \
					("The map is not surrounded by walls!!!", info);
				column++;
			}
		}
		else if (info->map[line][0] != '1'\
		|| info->map[line][info->width - 1] != '1')
			handler_errors_of_map("The map is not surrounded by walls!!!", \
			info);
		line++;
	}
}

void	get_textures(char *filepath, t_txrs *txrs) 
//  todo: сделать обработку букв вест и т.п. а также добавить пропуск переноса строки
{
	int fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		handler_errors(2);
	txrs->north = get_next_line(fd);
	txrs->south = get_next_line(fd);
	txrs->west = get_next_line(fd);
	txrs->north = get_next_line(fd);
	txrs->floor = get_next_line(fd);
	txrs->ceilling = get_next_line(fd);
	close(fd);
}

get_width(t_info *info)
{
	
}


void	parse_map(char *filepath, t_info *info)
{
	int	player;
	int	exits;
	t_txrs	txrs;

	if (!ext_of_map(filepath))
		handler_errors(3);
	get_textures(filepath, &txrs);
	read_map(filepath, info);
	check_chars_of_map(info, &player, &exits);
	get_width(info);
	if (player != 1)
		handler_errors_of_map("In MapFile must be only one player!!!", info);
	// check_walls(info);
}
