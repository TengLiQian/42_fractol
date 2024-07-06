/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:59:37 by lteng             #+#    #+#             */
/*   Updated: 2024/05/05 12:23:27 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
Real = x^2 - y^2
Imaginary = 2xyi
*/
t_complex	new_z(t_complex z, t_complex c)
{
	t_complex	new_z;

	new_z.x = (z.x * z.x) - (z.y * z.y) + c.x;
	new_z.y = (2 * z.x * z.y) + c.y;
	return (new_z);
}

// Rescale number based on old range and new range
double	ft_rescale(double num, double min_new, double max_new, double max_old)
{
	double	min_old;

	min_old = 0.0;
	return ((max_new - min_new) * (num - min_old) / (max_old - min_old)
		+ min_new);
}

double	parse_frac_part(char *str, int index)
{
	double	frac_part;
	double	power;

	frac_part = 0.0;
	power = 1.0;
	while (str[index] && ft_isdigit(str[index]) == 1)
	{
		power /= 10;
		frac_part += (str[index] - '0') * power;
		index++;
	}
	return (frac_part);
}

double	ft_atod(char *str)
{
	double	int_part;
	double	frac_part;
	int		sign;
	int		index;

	int_part = 0.0;
	frac_part = 0.0;
	sign = 1;
	index = 0;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (ft_isdigit(str[index]) == 1)
		int_part = int_part * 10 + (str[index++] - '0');
	if (str[index] == '.')
	{
		index++;
		frac_part = parse_frac_part(str, index);
	}
	return ((int_part + frac_part) * sign);
}
