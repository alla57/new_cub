/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:05:33 by alboumed          #+#    #+#             */
/*   Updated: 2021/11/18 17:14:31 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	skip_empty_lines(int fd, char **line)
{
	get_next_line(fd, &*line);
	while (empty_line(*line))
	{
		free(*line);
		if (get_next_line(fd, &*line) != 1)
			return (0);
	}
	return (1);
}

void	free_params(char **params)
{
	int	i;

	i = -1;
	while (params[++i])
		free(params[i]);
	free(params);
}

int	param_check(char **params, t_tools *tool)
{
	static int	a = 0;

	if (a == 255)
		return (1);
	else if (get_res(params, tool))
		a ^= (1 << 0);
	else if (get_north_texture(params, tool))
		a ^= (1 << 1);
	else if (get_south_texture(params, tool))
		a ^= (1 << 2);
	else if (get_west_texture(params, tool))
		a ^= (1 << 3);
	else if (get_east_texture(params, tool))
		a ^= (1 << 4);
	else if (get_sprite(params, tool))
		a ^= (1 << 5);
	else if (get_ground_color(params, tool))
		a ^= (1 << 6);
	else if (get_top_color(params, tool))
		a ^= (1 << 7);
	else if (params[0])
		a = 0;
	free_params(params);
	return (is_all_params_ok(a));
}

int	map_master(int fd, t_tools *tool)
{
	char			*line;
	unsigned int	max_x;
	int				j;

	max_x = 0;
	j = 0;
	if (!skip_empty_lines(fd, &line))
		return (0);
	while (map_check_line(line, tool))
	{
		if (max_x < ft_strlen(line))
			max_x = ft_strlen(line);
		realloc_map(tool);
		tool->map[j++] = ft_strdup(line);
		free(line);
		get_next_line(fd, &line);
	}
	free(line);
	return (map_master_two(j, max_x, tool));
}

int	get_map_param(char *path, t_tools *tool)
{
	char	*line;
	char	**params;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(1));
	get_next_line(fd, &line);
	params = ft_split(line, ' ');
	while (!param_check(params, tool))
	{
		free(line);
		if (get_next_line(fd, &line) != 1)
			return (ft_error(2));
		params = ft_split(line, ' ');
	}
	free(line);
	if (!map_master(fd, tool))
		return (ft_error(3));
	close(fd);
	return (param_check(params, tool));
}
