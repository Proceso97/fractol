/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:53:56 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 16:45:00 by jzarza-g         ###   ########.fr       */
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

int	get_color(int iter, int max_iter)
{
	int	red;
	int	green;
	int	blue;

	if (iter == max_iter)
		return (0x000000);
	red = (iter * 9) % 256;
	green = (iter * 15) % 256;
	blue = (iter * 25) % 256;
	return (create_trgb(0, red, green, blue));
}

void	zoom(t_data *data, int x, int y, double zoom_factor)
{
	double	mouse_re;
	double	mouse_im;
	double	interpolation;

	interpolation = 1.0 / zoom_factor;
	mouse_re = data->min_re + (x * (data->max_re - data->min_re) / WIDTH);
	mouse_im = data->min_im + (y * (data->max_im - data->min_im) / HEIGHT);
	data->max_re = mouse_re + (data->max_re - mouse_re) * interpolation;
	data->min_re = mouse_re + (data->min_re - mouse_re) * interpolation;
	data->max_im = mouse_im + (data->max_im - mouse_im) * interpolation;
	data->min_im = mouse_im + (data->min_im - mouse_im) * interpolation;
}
