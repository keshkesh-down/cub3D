#include "../includes/cub3D.h"

void	steve_animation(t_info	*info)
{
	static int	count;

	if (count == 0)
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE2, info);
	else if (count == 500)
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE3, info);
	else if (count == 1000)
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE4, info);
	else if (count == 1500)
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE5, info);
	else if (count == 2000)
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE6, info);
	else if (count == 2500)
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE7, info);
	else if (count == 3000)
	{
		draw_xpm_image(info->x * SCALE, info->y * SCALE, STEVE8, info);
		count = 0;
	}
	count++;
}

void	diamond_animation(t_info	*info)
{
	static int	count;
	int			i;
	int			j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			if (info->map[i][j] == 'C')
			{
				if (count == 0)
					draw_xpm_image(j * SCALE, i * SCALE, DIAMOND1, info);
				else if (count == 1000)
					draw_xpm_image(j * SCALE, i * SCALE, DIAMOND2, info);
				else if (count == 2000)
				{
					draw_xpm_image(j * SCALE, i * SCALE, DIAMOND3, info);
				}
			}
		}
	}
	if (count++ == 3000)
		count = 0;
}

void	portal_animation(t_info	*info)
{
	static int	count;

	count ++;
	if (count == 500)
		draw_xpm_image(info->exit_coordinates.x * SCALE, \
		info->exit_coordinates.y * SCALE, PORTAL1, info);
	else if (count == 1000)
		draw_xpm_image(info->exit_coordinates.x * SCALE, \
		info->exit_coordinates.y * SCALE, PORTAL2, info);
	else if (count == 1500)
		draw_xpm_image(info->exit_coordinates.x * SCALE, \
		info->exit_coordinates.y * SCALE, PORTAL3, info);
	else if (count == 2000)
		draw_xpm_image(info->exit_coordinates.x * SCALE, \
		info->exit_coordinates.y * SCALE, PORTAL4, info);
	else if (count == 2500)
		draw_xpm_image(info->exit_coordinates.x * SCALE, \
		info->exit_coordinates.y * SCALE, PORTAL5, info);
	else if (count == 3000)
	{
		draw_xpm_image(info->exit_coordinates.x * SCALE, \
		info->exit_coordinates.y * SCALE, PORTAL6, info);
		count = 0;
	}
}

void	creeper_animation(t_info	*info)
{
	static int	count;
	int			i;
	int			j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			if (info->map[i][j] == 'Q')
			{
				if (count == 750)
					draw_xpm_image(j * SCALE, i * SCALE, CREEPER1, info);
				else if (count == 1500 || count == 4500)
					draw_xpm_image(j * SCALE, i * SCALE, CREEPER2, info);
				else if (count == 2250 || count == 4750)
					draw_xpm_image(j * SCALE, i * SCALE, CREEPER3, info);
				else if (count == 3000 || count == 4000)
					draw_xpm_image(j * SCALE, i * SCALE, CREEPER4, info);
			}
		}
	}
	if (count++ == 5000)
		count = 0;
}
