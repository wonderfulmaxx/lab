#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include "lib42/libft.h"
# include <math.h>

# define screenWidth 708
# define screenHeight 512
# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533

typedef struct s_mlx
{
	// Variable for window
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	// Variable for player pos
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	// Variable for map
	int		mapX;
	int		mapY;
	int		mapS;
	int		*map;
	// Variable for Ray 3D
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		color;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	disT;
	float	disH;
	float	hx;
	float	hy;
	float	aTan;
	float	disV;
	float	vx;
	float	vy;
	float	nTan;
	float	ca;
	float	lineH;
	float	lineO;
	// color and texture
	int		color_roof;
	int		color_floor;
}	t_mlx;

// Function inits
void	init(t_mlx *vars);

// Function utils
void	my_mlx_pixel_put(t_mlx *vars, int x, int y, int colors);
void	clear_screen(t_mlx *vars);
void	draw_all(t_mlx *vars);
int		destroy_win(t_mlx *vars);


// Function draw map 2D
void	drawsquare(t_mlx *vars, int x_start, int y_start, int color);
void	drawMap2D(t_mlx *vars);

// Function draw Player 2D
void	drawPlayer(t_mlx *vars);

// Function draw line 2D
void	draw_line(t_mlx *vars, float startX, float startY, float endX, float endY,int color);

// Function draw Ray and Wall 3D
float	dist(float ax, float ay, float bx, float by, float ang);
void	drawRay3D(t_mlx *vars);
void	draw_wall(t_mlx *vars, float startX, float startY, float endX, float endY, int color);



#endif
