/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:55:02 by user42            #+#    #+#             */
/*   Updated: 2021/11/18 17:24:48 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_path_format(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	screen_size(t_tools *tool)
{
	int	x;
	int	y;

	tool->mlx_ptr = mlx_init();
	mlx_get_screen_size(tool->mlx_ptr, &x, &y);
	if (tool->res_x > x)
		tool->res_x = x;
	if (tool->res_y > y)
		tool->res_y = y;
	return (1);
}

int	ft_error(int error_code)
{
	if (error_code == 1)
		printf("error\nfile not found");
	else if (error_code == 2)
		printf("error\nparameters error");
	else if (error_code == 3)
		printf("error\nmap error");
	return (0);
}

int	minimize(t_tools *tool)
{
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr,
		tool->img_ptrnew, 0, 0);
	return (0);
}
