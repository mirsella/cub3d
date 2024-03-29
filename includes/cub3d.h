/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:03:45 by dly               #+#    #+#             */
/*   Updated: 2023/03/03 16:13:51 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h" // ft_*
# include "../mlx/mlx.h"
# include "struct.h" // struct
# include "define.h" 
# include <stdlib.h> // EXIT_*
# include <fcntl.h> // open()
# include <X11/keysym.h> // For X11 keycodes XK_*, see https://tronche.com/gui/x/xlib/input/keyboard-encoding.html

// free.c
int		free_map(t_map *map);

// map.c
int		parse_map(char *file, t_data *data);

#endif
