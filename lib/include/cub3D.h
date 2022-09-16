#ifndef CUB3D_H
# define CUB3D_H
# include "../minilibx/mlx.h"
# include <fcntl.h> //open, close, read, write
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free, perror, exit
# include <math.h> //mathematical functions
# include "../../lib/utils/get_next_line.h"

# define SCALE 75
# define KEYUP 13
# define KEYDOWN 1
# define KEYRIGHT 2
# define KEYLEFT 0
# define KEYW 126
# define KEYS 125
# define KEYD 124
# define KEYA 123

typedef struct s_exit_coordinates
{
	int	x;
	int	y;
}	t_exit_coordinates;

typedef struct s_txrs
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceilling;
}	t_txrs;

typedef struct s_info
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*width;
	int					height;
	char				**map;
	int					x;
	int					y;
	t_txrs				*txrs;
}	t_info;

void	parse_map(char *filename, t_info *info);
void	handler_errors(int number_of_error);
void	handler_errors_of_map(char *string_of_error, t_info *info);
void	check_chars_of_map(t_info *info, int *player, int *exits);
void	check_walls(t_info *info);
void	draw_game(t_info *info);
void	movement(t_info *info, int y, int x);
void	draw_xpm_image(int block_x, int block_y, char *texture, t_info *info);
int		all_animation(t_info *info);
void	steve_animation(t_info	*info);
void	diamond_animation(t_info	*info);
void	portal_animation(t_info	*info);
void	creeper_animation(t_info	*info);
void	find_portal(t_info *info);
void	exit_from_portal(t_info *info);
void	game_over(t_info *info);
int		free_and_exit(t_info *info);
char	*ft_itoa(int n);
void	draw_menu(t_info	info);
#endif
