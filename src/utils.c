/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:23:22 by tbrissia          #+#    #+#             */
/*   Updated: 2022/06/22 15:56:32 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_mlx *vars, int x, int y, int color)
{
	char	*dst;
	dst = vars->addr + (y * vars->line_length + x * (vars->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	clear_screen(t_mlx *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bit_per_pixel, &vars->line_length,
									&vars->endian);
}

int	destroy_win(t_mlx *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	draw_all(t_mlx *vars)
{
	clear_screen(vars);
	drawRay3D(vars);
	drawPlayer(vars);
	drawMap2D(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
