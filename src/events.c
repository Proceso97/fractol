/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:57:07 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 16:30:00 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	mouse_handler(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_WHEEL_UP)
	{
		zoom(data, x, y, 1.1);
		redraw_fractal(data);
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		zoom(data, x, y, 0.9);
		redraw_fractal(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	move_view(t_data *data, double move_re, double move_im)
{
	data->min_re += move_re;
	data->max_re += move_re;
	data->min_im += move_im;
	data->max_im += move_im;
}

static void	handle_movement(t_data *data, double move_re, double move_im)
{
	move_view(data, move_re, move_im);
	redraw_fractal(data);
}

int	key_handler(int keycode, t_data *data)
{
	double	move_factor;

	move_factor = (data->max_re - data->min_re) * 0.1;
	if (keycode == ESC_KEY)
		close_window(data);
	else if (keycode == ARROW_LEFT)
		handle_movement(data, -move_factor, 0);
	else if (keycode == ARROW_RIGHT)
		handle_movement(data, move_factor, 0);
	else if (keycode == ARROW_UP)
		handle_movement(data, 0, -move_factor);
	else if (keycode == ARROW_DOWN)
		handle_movement(data, 0, move_factor);
	return (0);
}
