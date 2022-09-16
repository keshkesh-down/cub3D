#include "../includes/cub3D.h"

void	draw_count_of_moves(t_info *info)
{
	char	*moves;

	moves = ft_itoa(++info->moves);
	draw_xpm_image(0, 15, FIELD, info);
	mlx_string_put(info->mlx, info->win, 0, 15, 0xFFFFFFFF, "Count of steps:");
	mlx_string_put(info->mlx, info->win, 150, 15, 0xFFFFFFFF, moves);
	free(moves);
}

void	movement(t_info *info, int y, int x)
{
	char	map_char;

	map_char = info->map[y][x];
	if (map_char == 'E' && info->collectibles == -1)
		exit_from_portal(info);
	if (map_char == '1' || map_char == 'E')
		return ;
	else if (map_char == '0')
	{
		draw_xpm_image(info->x * SCALE, info->y * SCALE, FLOOR, info);
		draw_xpm_image(x * SCALE, y * SCALE, STEVE1, info);
	}
	else if (map_char == 'C')
	{
		draw_xpm_image(info->x * SCALE, info->y * SCALE, FLOOR, info);
		draw_xpm_image(x * SCALE, y * SCALE, STEVE1, info);
		info->map[y][x] = '0';
		--info->collectibles;
	}
	else if (map_char == 'Q')
		game_over(info);
	info->y = y;
	info->x = x;
	draw_count_of_moves(info);
}

void	open_portal(t_info *info)
{
	draw_xpm_image(info->exit_coordinates.x * SCALE, \
	info->exit_coordinates.y * SCALE, PORTAL1, info);
	info->collectibles = -1;
}

int	all_animation(t_info *info)
{
	steve_animation(info);
	diamond_animation(info);
	creeper_animation(info);
	if (info->collectibles == 0)
		open_portal(info);
	if (info->collectibles == -1)
		portal_animation(info);
	return (0);
}
