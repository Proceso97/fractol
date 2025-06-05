/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:21:40 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 12:21:40 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	render_mandelbrot(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	init_fractal_data(&data);
	draw_mandelbrot(&data);
	mlx_hook(data.win, CLOSE_WIN, 0, close_window, &data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

void	render_julia(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Julia Set");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	init_julia_data(&data);
	draw_julia(&data);
	mlx_hook(data.win, CLOSE_WIN, 0, close_window, &data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

void	render_burning_ship(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Burning Ship");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	init_burning_ship_data(&data);
	draw_burning_ship(&data);
	mlx_hook(data.win, CLOSE_WIN, 0, close_window, &data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
