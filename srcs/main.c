/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:58:46 by dly               #+#    #+#             */
/*   Updated: 2023/03/02 18:08:00dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_map(t_data *data)
{
	if (data->map->mlx && data->map->win)
		mlx_destroy_window(data->map->mlx, data->map->win);
	if (data->map->mlx)
		mlx_destroy_display(data->map->mlx);
	if (data->map->mlx)
		free(data->map->mlx);
	if (data->map)
		free(data->map);
	return (0);
}

int	end_game(t_data *data)
{
	free_map(data);
	exit(EXIT_SUCCESS);
}

int	init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	data->map->mlx = NULL;
	data->map->win = NULL;
	data->map->map_matrix = NULL;
	return (0);
}

int	assign_map(t_data *data)
{
	data->map->mlx = mlx_init();
	if (!data->map->mlx)
		return (free_map(data), 1);
	data->map->win = mlx_new_window(data->map->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!data->map->win)
		return (free_map(data), 1);

	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		end_game(data);
	if (keycode == KEY_W)
		end_game(data);
	if (keycode == KEY_A)
		end_game(data);
	if (keycode == KEY_S)
		end_game(data);
	if (keycode == KEY_D)
		end_game(data);
	if (keycode == KEY_L_ARROW)
		end_game(data);
	if (keycode == KEY_R_ARROW)
		end_game(data);
	if (keycode == KEY_SPC)
		end_game(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	(void)envp;
	if (argc != 2)
		return (1);
	if (init_map(&data))
		return (2);
	assign_map(&data);
	mlx_hook(data.map->win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.map->win, 17, 0, end_game, &data);
	mlx_loop(data.map->mlx);
	return (0);
}
