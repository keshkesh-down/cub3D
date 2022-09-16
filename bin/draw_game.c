#include "../includes/cub3D.h"

void	draw_xpm_image(int block_x, int block_y, char *texture, t_info *info)
{
	int	width;
	int	height;

	info->img = mlx_xpm_file_to_image(info->mlx, texture, &width, &height);
	mlx_put_image_to_window(info->mlx, info->win, info->img, block_x, block_y);
}

void	put_image(int block_x, int block_y, char map_char, t_info *info)
{
	if (map_char == '1')
		draw_xpm_image(block_x, block_y, WALL, info);
	else if (map_char == '0')
		draw_xpm_image(block_x, block_y, FLOOR, info);
	else if (map_char == 'C')
		draw_xpm_image(block_x, block_y, DIAMOND1, info);
	else if (map_char == 'P')
	{
		info->x = block_x / SCALE;
		info->y = block_y / SCALE;
		draw_xpm_image(block_x, block_y, FLOOR, info);
		draw_xpm_image(block_x, block_y, STEVE1, info);
		info->map[info->y][info->x] = '0';
	}
	else if (map_char == 'E')
		draw_xpm_image(block_x, block_y, CLOSE_PORTAL, info);
	else if (map_char == 'H' || map_char == 'V')
		draw_xpm_image(block_x, block_y, CREEPER1, info);
}

void	draw_game(t_info *info)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = 0;
	while (pixel_y < info->height)
	{
		pixel_x = 0;
		while (pixel_x < info->width)
		{
			put_image(pixel_x * SCALE, pixel_y * SCALE, \
			info->map[pixel_y][pixel_x], info);
			pixel_x++;
		}
		pixel_y++;
	}
}
