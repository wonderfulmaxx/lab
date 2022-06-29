/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrissia <tbrissia@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:16:07 by tbrissia          #+#    #+#             */
/*   Updated: 2022/06/23 13:37:48 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_mlx *vars)
{
	int	i = 0;
	int map[]=
	{
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,1,0,0,1,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,
	};
	vars->mapX = 8;
	vars->mapY = 8;
	vars->mapS = 64;
	vars->map = (int *)malloc(sizeof(int) * vars->mapS);
	while (i < vars->mapS)
	{
		vars->map[i] = map[i];
		i++;
	}
	vars->color_roof = 0xF5F57B;
	vars->color_floor = 0xC1B156;
	vars->px = 256;
	vars->py = 256;
	vars->pdx = cos(vars->pa) * 5;
	vars->pdy = sin(vars->pa) * 5;
	draw_all(vars);
}
