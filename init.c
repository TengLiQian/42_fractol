/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:21:31 by lteng             #+#    #+#             */
/*   Updated: 2024/05/18 16:00:22 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initialise the mlx connection and window
void	fract_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		ft_putstr_fd("Error Initializing MinilibX", 2);
		exit(1);
	}
	fractal->mlx_window = NULL;
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
}

// Initialise the image and get the address
void	image_init(t_fractal *fractal)
{
	fractal->image.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	fractal->image.addr = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bits_per_pixel, &fractal->image.line_length,
			&fractal->image.endian);
}

// Set the fractal's default parameters
void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

// Initialise events for interactivity
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, 1L << 0, key_input, fractal);
	mlx_hook(fractal->mlx_window, 4, 1L << 2, mouse_zoom, fractal);
	mlx_hook(fractal->mlx_window, 17, 0L, close_window, fractal);
}

void	full_init(t_fractal *fractal)
{
	fract_init(fractal);
	image_init(fractal);
	data_init(fractal);
	events_init(fractal);
}
