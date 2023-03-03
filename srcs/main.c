/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:58:46 by dly               #+#    #+#             */
/*   Updated: 2023/03/03 16:13:12 by lgillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	end_game(t_data *data)
{
	free_map(&data->map);
	exit(EXIT_SUCCESS);
}

int	assign_map(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (free_map(map), 1);
	map->win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!map->win)
		return (free_map(map), 1);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		end_game(data);
	if (keycode == XK_W)
		end_game(data);
	if (keycode == XK_A)
		end_game(data);
	if (keycode == XK_S)
		end_game(data);
	if (keycode == XK_D)
		end_game(data);
	if (keycode == XK_Left)
		end_game(data);
	if (keycode == XK_Right)
		end_game(data);
	if (keycode == XK_space)
		end_game(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	(void)envp;
	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		return (1);
	if (parse_map(argv[1], &data))
		return (3);
	assign_map(&data.map);
	mlx_hook(data.map.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.map.win, 17, 0, end_game, &data);
	mlx_loop(data.map.mlx);
	return (0);
}
