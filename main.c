/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:54:06 by lteng             #+#    #+#             */
/*   Updated: 2024/05/18 15:42:08 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0) || (argc == 4
			&& ft_strcmp(argv[1], "julia") == 0))
	{
		fractal.name = argv[1];
		if (ft_strcmp(argv[1], "julia") == 0)
		{
			fractal.julia_x = ft_atod(argv[2]);
			fractal.julia_y = ft_atod(argv[3]);
		}
		full_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Only accept: \n  1. mandelbrot\n  2. julia <x> <y>\n", 2);
		exit(1);
	}
	return (0);
}
