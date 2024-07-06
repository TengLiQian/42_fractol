/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:53:28 by lteng             #+#    #+#             */
/*   Updated: 2024/05/18 15:54:09 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define BUTTON4 4
# define BUTTON5 5

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLUS 65451
# define MINUS 65453

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;

	t_data	image;

	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;

	double	julia_x;
	double	julia_y;

}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// Init
void		fract_init(t_fractal *fractal);
void		image_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		full_init(t_fractal *fractal);

// Utils
t_complex	new_z(t_complex z, t_complex c);
double		ft_rescale(double num, double min_new, double max_new,
				double max_old);
double		parse_frac_part(char *str, int index);
double		ft_atod(char *str);
int			ft_strcmp(char *s1, char *s2);

// Render
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		mandelbrot_setup(int x, int y, t_fractal *fractal);
void		julia_setup(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

// Events
int			close_window(t_fractal *fractal);
int			key_input(int keysym, t_fractal *fractal);
int			mouse_zoom(int button, int x, int y, t_fractal *fractal);

#endif
