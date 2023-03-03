/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:00:51 by lgillard          #+#    #+#             */
/*   Updated: 2023/03/03 16:13:40 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file(char *file, t_data *data)
{
	int	fd;

	if (!ft_strnstr(file + ft_strlen(file) - 4, ".cub", 4))
		return (ft_putstr_fd(INV_FILE, 2), free_map(&data->map), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd(INV_FILE_NOT_FOUND, 2), free_map(&data->map), 1);
	return (0);
}

int	parse_map(char *file, t_data *data)
{
	if (check_file(file, data))
		return (1);
	return (0);
}
