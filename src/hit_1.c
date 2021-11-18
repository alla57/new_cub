/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:47:15 by alboumed          #+#    #+#             */
/*   Updated: 2021/11/18 17:15:41 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	hit_north(t_tools *tool)
{
	int	x;
	int	y;

	y = (int)tool->posy;
	x = (int)tool->posx;
	if (tool->map[y - 1][x] == '1')
	{
		if ((tool->posy - tool->speed) <= (y))
			return (1);
	}
	return (0);
}

int	hit_south(t_tools *tool)
{
	int	x;
	int	y;

	y = (int)tool->posy;
	x = (int)tool->posx;
	if (tool->map[y + 1][x] == '1')
	{
		if ((tool->posy + tool->speed) >= (y + 1))
			return (1);
	}
	return (0);
}

int	hit_east(t_tools *tool)
{
	int	x;
	int	y;

	y = (int)tool->posy;
	x = (int)tool->posx;
	if (tool->map[y][x + 1] == '1')
	{
		if ((tool->posx + tool->speed) >= (x + 1))
			return (1);
	}
	return (0);
}

int	hit_west(t_tools *tool)
{
	int	x;
	int	y;

	y = (int)tool->posy;
	x = (int)tool->posx;
	if (tool->map[y][x - 1] == '1')
	{
		if ((tool->posx - tool->speed) <= (x))
			return (1);
	}
	return (0);
}
