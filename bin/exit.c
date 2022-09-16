#include "../includes/cub3D.h"

int	free_and_exit(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

void	exit_from_portal(t_info *info)
{
	printf("%s%i%s", "My greetings, you make ", \
	++info->moves, " steps and win!!!\n");
	free_and_exit(info);
}

void	game_over(t_info *info)
{
	printf("%s", "GAME OVER!!!\n");
	free_and_exit(info);
}
