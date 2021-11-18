/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:08:12 by alla              #+#    #+#             */
/*   Updated: 2021/11/18 18:54:15 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_all_params_ok(int a)
{
	if (a == 255)
		return (1);
	return (0);
}

int	column_plus_or_minus(t_tools *tool, int column)
{
	if (cos(tool->dir) > 0)
		return (++column);
	else
		return (--column);
}

int	row_plus_or_minus(t_tools *tool, int row)
{
	if (sin(tool->dir) > 0)
		return (--row);
	else
		return (++row);
}
