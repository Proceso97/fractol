/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:58:13 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 10:58:13 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	init_fractal_data(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 1.0;
	data->min_im = -1.5;
	data->max_im = 1.5;
	data->max_iter = 100;
	data->fractal_type = MANDELBROT;
}

void	init_julia_data(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = 2.0;
	data->min_im = -2.0;
	data->max_im = 2.0;
	data->max_iter = 100;
	data->fractal_type = JULIA;
	data->julia_c_re = -0.8;
	data->julia_c_im = 0.156;
}

void	init_burning_ship_data(t_data *data)
{
	data->min_re = -2.5;
	data->max_re = 1.5;
	data->min_im = -2.0;
	data->max_im = 2.0;
	data->max_iter = 100;
	data->fractal_type = BURNING_SHIP;
}
