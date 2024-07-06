/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:16:16 by lteng             #+#    #+#             */
/*   Updated: 2024/05/18 15:56:53 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
}

int	key_input(int keysym, t_fractal *fractal)
{
	if (keysym == ESC)
		close_window(fractal);
	else if (keysym == LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == PLUS)
		fractal->iterations += 10;
	else if (keysym == MINUS)
		fractal->iterations -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == BUTTON4)
		fractal->zoom *= 0.95;
	else if (button == BUTTON5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
