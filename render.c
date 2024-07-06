/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:23:45 by lteng             #+#    #+#             */
/*   Updated: 2024/05/18 16:10:01 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
Mandelbrot
Z = Z^2 + C

Z is (0, 0)
C is the actual point

Z0 = 0 + (C1, C2)
Z1 = (C1, C2) ^ 2 + (C1, C2)
*/

void	mandelbrot_setup(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	colour = 0;
	z.x = 0;
	z.y = 0;
	c.x = ft_rescale(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = ft_rescale(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	while (i < fractal->iterations)
	{
		z = new_z(z, c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			colour = ft_rescale(i, BLACK, WHITE, fractal->iterations);
			my_mlx_pixel_put(&fractal->image, x, y, colour);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->image, x, y, BLACK);
}

/*
Julia
./fractol julia <x> <y>
Z is the actual point
C is the constant (x, y)
*/

void	julia_setup(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	colour = 0;
	z.x = ft_rescale(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = ft_rescale(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	while (i < fractal->iterations)
	{
		z = new_z(z, c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			colour = ft_rescale(i, BLACK, WHITE, fractal->iterations);
			my_mlx_pixel_put(&fractal->image, x, y, colour);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->image, x, y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;
	char	*str_iterations;
	char	*final;

	y = -1;
	str_iterations = ft_itoa(fractal->iterations);
	final = ft_strjoin("Iterations = ", str_iterations);
	while (++y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strcmp(fractal->name, "mandelbrot") == 0)
				mandelbrot_setup(x++, y, fractal);
			else if (ft_strcmp(fractal->name, "julia") == 0)
				julia_setup(x++, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.img, 0, 0);
	mlx_string_put(fractal->mlx_connection, fractal->mlx_window, 700, 780,
		WHITE, final);
	(void)(free(final), free(str_iterations));
}
