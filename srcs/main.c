/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:58:46 by dly               #+#    #+#             */
/*   Updated: 2023/03/02 16:38:34 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_map(t_map *map)
{
	if (map->mlx && map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	return (0);
}

int	end_game(t_map *map)
{
	free_map(map);
	exit(EXIT_SUCCESS);
}

int	init_map(t_map *map)
{
	map->mlx = NULL;
	map->win = NULL;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_map	map;

	(void)argv;
	(void)envp;
	if (argc != 2)
		return (1);
	if (init_map(&map))
		return (2);
	map.mlx = mlx_init();
	if (!map.mlx)
		return (free_map(&map), 1);
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!map.win)
		return (free_map(&map), 1);
	mlx_hook(map.win, 17, 0, end_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
