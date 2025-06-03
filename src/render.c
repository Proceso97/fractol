/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:12:46 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/02 19:12:46 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int	mandelbrot_iteration(double c_re, double c_im, int max_iter)
{
    double	zx;
    double	zy;
    double	tmp;
    int		iter;

    zx = 0.0;
    zy = 0.0;
    iter = 0;
    while (iter < max_iter && (zx * zx + zy * zy) < 4.0)
    {
        tmp = zx * zx - zy * zy + c_re;
        zy = 2.0 * zx * zy + c_im;
        zx = tmp;
        iter++;
    }
    return (iter);
}

int	get_color(int iter, int max_iter)
{
    int	r;
    int	g;
    int	b;

    if (iter == max_iter)
        return (0x000000);
    r = (iter * 9) % 256;
    g = (iter * 15) % 256;
    b = (iter * 25) % 256;
    return (create_trgb(0, r, g, b));
}

void	draw_mandelbrot(t_data *data)
{
    int		x;
    int		y;
    double	c_re;
    double	c_im;
    int		iter;
    int		color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c_re = data->min_re + (x * (data->max_re - data->min_re) / WIDTH);
            c_im = data->min_im + (y * (data->max_im - data->min_im) / HEIGHT);
            iter = mandelbrot_iteration(c_re, c_im, data->max_iter);
            color = get_color(iter, data->max_iter);
            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
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

int	key_handler(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

void	init_fractal_data(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 1.0;
	data->min_im = -1.5;
	data->max_im = 1.5;
	data->max_iter = 100;
}

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
    
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);
}