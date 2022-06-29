/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:35:52 by tbrissia          #+#    #+#             */
/*   Updated: 2022/06/23 13:21:00 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int mov(int keycode, t_mlx *vars)
{
	if (keycode == 0) // a
	{
		vars->pa -= 0.1;
		if (vars->pa < 0)
			vars->pa += 2 * PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}
	if (keycode == 123) // <-
	{
		vars->pa -= 0.1;
		if (vars->pa < 0)
			vars->pa += 2 * PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}
	if (keycode == 2) //d
	{
		vars->pa += 0.1;
		if (vars->pa > 2 * PI)
			vars->pa -= 2 * PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}
	if (keycode == 124) // ->
	{
		vars->pa += 0.1;
		if (vars->pa > 2 * PI)
			vars->pa -= 2 * PI;
		vars->pdx = cos(vars->pa) * 5;
		vars->pdy = sin(vars->pa) * 5;
	}

	// Colision
	int xo = 0;
	if (vars->pdx < 0)
		xo = -20;
	else
		xo = 20;
	int yo = 0;
	if (vars->pdy < 0)
		yo = -20;
	else
		yo = 20;
	int ipx = vars->px / 64.0, ipx_add_xo = (vars->px + xo) / 64.0, ipx_sub_xo = (vars->px - xo) / 64.0;
	int ipy = vars->py / 64.0, ipy_add_yo = (vars->py + yo) / 64.0, ipy_sub_yo = (vars->py - yo) / 64.0;
	if (keycode == 13 || keycode == 126) //w
	{
		if (vars->map[ipy * vars->mapX + ipx_add_xo] == 0)
			vars->px += vars->pdx * 2.5;
		if (vars->map[ipy_add_yo * vars->mapX + ipx] == 0)
			vars->py += vars->pdy * 2.5;
	}
	if (keycode == 1 || keycode == 125) //s
	{
		if (vars->map[ipy * vars->mapX + ipx_sub_xo] == 0)
			vars->px -= vars->pdx * 2.5;
		if (vars->map[ipy_sub_yo * vars->mapX + ipx] == 0)
			vars->py -= vars->pdy * 2.5;
	}
	if (keycode == 53)
		destroy_win(vars);
	draw_all(vars);
	return(0);
}

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_mlx	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Cub3d");
	vars.img = mlx_new_image(vars.mlx, screenWidth, screenHeight);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bit_per_pixel, &vars.line_length, &vars.endian);
	init(&vars);
	mlx_hook(vars.win, 2, 1L << 0, mov, &vars);
	mlx_hook(vars.win, 17, 1L << 17, destroy_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
