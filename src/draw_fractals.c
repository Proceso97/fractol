/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:23:26 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 12:23:26 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	double	c_re;
	double	c_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_re = data->min_re + (x * (data->max_re - data->min_re) / WIDTH);
			c_im = data->min_im + (y * (data->max_im - data->min_im) / HEIGHT);
			iter = mandelbrot_iteration(c_re, c_im, data->max_iter);
			my_mlx_pixel_put(data, x, y, get_color(iter, data->max_iter));
			x++;
		}
		y++;
	}
}

void	draw_julia(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	double	z_re;
	double	z_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_re = data->min_re + (x * (data->max_re - data->min_re) / WIDTH);
			z_im = data->min_im + (y * (data->max_im - data->min_im) / HEIGHT);
			iter = julia_iteration(z_re, z_im, data);
			my_mlx_pixel_put(data, x, y, get_color(iter, data->max_iter));
			x++;
		}
		y++;
	}
}

void	draw_burning_ship(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	double	c_re;
	double	c_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_re = data->min_re + (x * (data->max_re - data->min_re) / WIDTH);
			c_im = data->min_im + (y * (data->max_im - data->min_im) / HEIGHT);
			iter = burning_ship_iteration(c_re, c_im, data->max_iter);
			my_mlx_pixel_put(data, x, y, get_color(iter, data->max_iter));
			x++;
		}
		y++;
	}
}

void	redraw_fractal(t_data *data)
{
	if (data->fractal_type == MANDELBROT)
		draw_mandelbrot(data);
	else if (data->fractal_type == JULIA)
		draw_julia(data);
	else if (data->fractal_type == BURNING_SHIP)
		draw_burning_ship(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
