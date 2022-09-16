#include "../lib/include/cub3D.h"

// int	key_hook(int keycode, t_info *info)
// {
// 	if (keycode == KEYUP || keycode == KEYW)
// 		movement(info, info->y - 1, info->x);
// 	else if (keycode == KEYDOWN || keycode == KEYS)
// 		movement(info, info->y + 1, info->x);
// 	else if (keycode == KEYRIGHT || keycode == KEYD)
// 		movement(info, info->y, info->x + 1);
// 	else if (keycode == KEYLEFT || keycode == KEYA)
// 		movement(info, info->y, info->x - 1);
// 	else if (keycode == 53)
// 		free_and_exit(info);
// 	return (0);
// }

void	init_info(t_info *info)
{
	info->height = 0;
	info->width = 0;
	info->x = 0;
	info->y = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		handler_errors(1);
	init_info(&info);
	parse_map(argv[1], &info);
	// info.mlx = mlx_init();
	// info.win = mlx_new_window(info.mlx, info.width * SCALE, info.height * SCALE, TITLE);
	// find_portal(&info);
	// draw_game(&info);
	// mlx_hook(info.win, 2, 0, key_hook, &info);
	// mlx_loop_hook(info.mlx, all_animation, &info);
	// mlx_hook(info.win, 17, 0, free_and_exit, &info);
	// mlx_loop(info.mlx);
	return (0);
}
