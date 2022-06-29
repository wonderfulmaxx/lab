/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:19:18 by tbrissia          #+#    #+#             */
/*   Updated: 2022/06/22 17:07:22 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_mlx *vars, float startX, float startY, float endX, float endY,int color)
{
	float 	deltaX;
	float 	deltaY;
	float 	pixelX;
	float 	pixelY;
	int		pixels;

	deltaX = endX - startX;
	deltaY = endY - startY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	pixelX = startX;
	pixelY = startY;
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
	    my_mlx_pixel_put(vars, pixelX, pixelY, color);
	    pixelX += deltaX;
	    pixelY += deltaY;
	    --pixels;
	}
}

void	drawPlayer(t_mlx *vars)
{
	float 	x_counter;
	float	y_counter;
	int		color;

	y_counter = 0;

	color = 0xFFFFFF;
	while (y_counter < 10)
	{
		x_counter = 0;
		while(x_counter < 10)
		{
			my_mlx_pixel_put(vars, (vars->px + x_counter) / 3, (vars->py + y_counter) / 3, color);
			x_counter ++;
		}
		y_counter ++;
	}
	// draw_line(vars, (vars->px / 3) + 1, (vars->py / 3) + 1, ((vars->px + vars->pdx * 5) / 3) + 1, ((vars->py + vars->pdy * 5) / 3) + 1, color);
}

void	drawsquare(t_mlx *vars, int x_start, int y_start, int color)
{
	int x_counter;
	int y_counter;

	x_start += 1;
	y_start += 1;
	x_counter = 0;
	while (x_counter < 21)
	{
		y_counter = 0;
		while (y_counter < 21)
		{
			my_mlx_pixel_put(vars, x_counter + x_start, y_counter + y_start, color);
			y_counter ++;
		}
		x_counter ++;
	}
}

void drawMap2D(t_mlx *vars)
{
	int x_counter;
	int y_counter;

	y_counter = 0;
	while (y_counter < vars->mapY)
	{
		x_counter = 0;
		while (x_counter < vars->mapX)
		{
			if (vars->map[y_counter * vars->mapX + x_counter] == 1)
				drawsquare(vars, x_counter * 21, y_counter * 21, 0x00FFFFFF);
			x_counter++;

		}
		y_counter++;
	}
}
