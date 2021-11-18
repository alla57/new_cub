/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:42:55 by alboumed          #+#    #+#             */
/*   Updated: 2021/11/13 17:10:31 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_sprite(t_tools *tool, int i, int j)
{
	double	x;
	double	y;
	double	t;

	x = (double)i + 0.5;
	y = (double)j + 0.5;
	t = (x - (double)i) / sin(tool->dir);
	x = x - sin(tool->dir) * t;
	y = y - cos(tool->dir) * t;
	if ((int)x == i && (int)y == (j))
	{
		tool->hit[2] = tool->hit[0];
	}
	else
	{
		tool->hit[2] = tool->hit[1];
	}
}

void	hit_sprite(t_tools *tool, int i, int j)
{
	double	x;
	double	y;
	double	t;

	x = (double)i + 0.5;
	y = (double)j + 0.5;
	t = (cos(tool->dir) * tool->posy - sin(tool->dir) * x + sin(tool->dir)
			* tool->posx - cos(tool->dir) * y) / (-1 * (cos(tool->dir)
				* cos(tool->dir) + sin(tool->dir) * sin(tool->dir)));
	x = x - sin(tool->dir) * t;
	y = y - cos(tool->dir) * t;
	if (x < (double)i)
	{
		tool->sprite_col = 0;
		tool->sprite_row = 0;
		return ;
	}
	tool->hit[0] = x;
	tool->hit[1] = y;
	rotate_sprite(tool, i, j);
}
