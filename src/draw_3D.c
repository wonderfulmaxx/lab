/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:17:43 by tbrissia          #+#    #+#             */
/*   Updated: 2022/06/23 13:35:08 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float dist(float ax, float ay, float bx, float by, float ang)
{
	(void)ang;
	return (sqrt((bx - ax) * (bx-ax) + (by-ay) * (by - ay)));
}

void	drawRay3D(t_mlx *vars)
{
	vars->ra = vars->pa - DR * 30;
	if (vars->ra < 0)
		vars->ra += 2 * PI;
	if (vars->ra > 2 * PI)
		vars->ra -= 2 * PI;
	for (vars->r = 0; vars->r < 60 ; vars->r ++)
	{
		vars->dof = 0;
		vars->disH = 1000000, vars->hx = vars->px , vars->hy = vars->py;
		vars->aTan = -1/tan(vars->ra);
		if (vars->ra > PI)
		{
			vars->ry = (((int)vars->py>>6)<<6) - 0.0001;
			vars->rx = (vars->py - vars->ry) * vars->aTan + vars->px;
			vars->yo = -vars->mapS;
			vars->xo = -vars->yo * vars->aTan;
		}
		if (vars->ra < PI)
		{
			vars->ry = (((int)vars->py>>6)<<6) + vars->mapS;
			vars->rx = (vars->py - vars->ry) * vars->aTan + vars->px;
			vars->yo = vars->mapS;
			vars->xo = -vars->yo * vars->aTan;
		}
		if (vars->ra == 0 || vars->ra == PI)
		{
			vars->rx = vars->px;
			vars->ry = vars->py;
			vars->dof = 8;
		}
		while (vars->dof < 8)
		{
			vars->mx = (int)(vars->rx)>>6;
			vars->my = (int)(vars->ry)>>6;
			vars->mp = vars->my * vars->mapX + vars->mx;
			if (vars->mp > 0 && vars->mp < vars->mapX * vars->mapY && vars->map[vars->mp] > 0)
			{
				vars->hx = vars->rx;
				vars->hy = vars->ry;
				vars->disH = dist(vars->px,vars->py,vars->hx,vars->hy,vars->ra);
				vars->dof = 8;
			}
			else
			{
				vars->rx += vars->xo; // TODO: pb ici
				vars->ry += vars->yo;
				vars->dof += 1;
			}
		}
		vars->dof = 0;
		vars->disV = 1000000, vars->vx = vars->px , vars->vy = vars->py;
		vars->nTan = -tan(vars->ra);
		if (vars->ra > P2 && vars->ra < P3)
		{
			vars->rx = (((int)vars->px>>6)<<6) - 0.0001;
			vars->ry = (vars->px - vars->rx) * vars->nTan + vars->py;
			vars->xo = -vars->mapS;
			vars->yo = -vars->xo * vars->nTan;
		}
		if (vars->ra < P2 || vars->ra > P3)
		{
			vars->rx = (((int)vars->px>>6)<<6) + vars->mapS;
			vars->ry = (vars->px - vars->rx) * vars->nTan + vars->py;
			vars->xo = vars->mapS;
			vars->yo = -vars->xo * vars->nTan;
		}
		if (vars->ra == 0 || vars->ra == PI)
		{
			vars->rx = vars->px;
			vars->ry = vars->py;
			vars->dof = 8;
		}
		while (vars->dof < 8)
		{
			vars->mx = (int)(vars->rx)>>6;
			vars->my = (int)(vars->ry)>>6;
			vars->mp = vars->my * vars->mapX + vars->mx;
			if (vars->mp > 0 && vars->mp < vars->mapX * vars->mapY && vars->map[vars->mp] > 0)
			{
				vars->vx = vars->rx;
				vars->vy = vars->ry;
				vars->disV = dist(vars->px, vars->py, vars->vx, vars->vy, vars->ra);
				vars->dof = 8;
			}
			else
			{
				vars->rx += vars->xo;
				vars->ry += vars->yo;
				vars->dof += 1;
			}
		}
		if (vars->disV < vars->disH)
		{
			vars->rx = vars->vx;
			vars->ry = vars->vy;
			vars->disT = vars->disV;
			vars->color = 0xd0d079;
		}
		if (vars->disH < vars->disV)
		{
			vars->rx = vars->hx;
			vars->ry = vars->hy;
			vars->disT = vars->disH;
			vars->color = 0x9f9f5b;
		}
		// draw_line(vars, (vars->px / 3) + 1, (vars->py / 3) + 1, (vars->rx) / 3, (vars->ry) / 3, 0x888689);
		draw_line(vars, (vars->px / 3) + 1, (vars->py / 3) + 1, vars->rx / 3, vars->ry / 3, 0x888689);
		vars->ca = vars->pa - vars->ra;
		if (vars->ca < 0)
			vars->ca += 2 * PI;
		if (vars->ca > 2 * PI)
			vars->ca -= 2 * PI;
		vars->disT = vars->disT * cos(vars->ca);
		vars->lineH = (vars->mapS * 512) / vars->disT;
		if (vars->lineH > 512)
			vars->lineH = 512;
		vars->lineO = 256 - vars->lineH / 2;
		draw_wall(vars, vars->r * 12 + 0, 0, (vars->r * 12 + 0) + 12, vars->lineO, vars->color_roof);
		draw_wall(vars, vars->r * 12 + 0, vars->lineO, (vars->r * 12 + 0) + 12, vars->lineH + vars->lineO, vars->color);
		draw_wall(vars, vars->r * 12 + 0, vars->lineH + vars->lineO, (vars->r * 12 + 0) + 12, 512, vars->color_floor);
		vars->ra += DR;
		if (vars->ra < 0)
			vars->ra += 2 * PI;
		if (vars->ra > 2 * PI)
			vars->ra -= 2 * PI;
	}
}

void	draw_wall(t_mlx *vars, float startX, float startY, float endX, float endY, int color)
{
	float	y;
	float	x;

	y = startY;
	x = startX;
	while (y < endY)
	{
		x = startX;
		while (x < endX)
		{
			my_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}
