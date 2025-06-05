/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:16 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 15:45:00 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

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

int	julia_iteration(double z_re, double z_im, t_data *data)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < data->max_iter && (z_re * z_re + z_im * z_im) < 4.0)
	{
		tmp = z_re * z_re - z_im * z_im + data->julia_c_re;
		z_im = 2.0 * z_re * z_im + data->julia_c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

int	burning_ship_iteration(double c_re, double c_im, int max_iter)
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
		zy = 2.0 * fabs(zx * zy) + c_im;
		zx = tmp;
		iter++;
	}
	return (iter);
}
