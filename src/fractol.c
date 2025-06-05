/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:56:28 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/05/28 19:56:28 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	is_valid_fractal(char *name)
{
	if (!name)
		return (0);
	if (!ft_strncmp(name, "mandelbrot", 10))
		return (1);
	if (!ft_strncmp(name, "julia", 5))
		return (2);
	if (!ft_strncmp(name, "burning_ship", 12))
		return (3);
	return (0);
}

void	print_help(void)
{
	ft_printf("Uso: ./fractol <fractal>\n");
	ft_printf("Fractales disponibles:\n");
	ft_printf("  mandelbrot\n");
	ft_printf("  julia\n");
	ft_printf("  burning_ship\n");
}

int	main(int argc, char **argv)
{
	int	fractal_type;

	if (argc != 2)
	{
		print_help();
		return (1);
	}
	fractal_type = is_valid_fractal(argv[1]);
	if (fractal_type == 0)
	{
		print_help();
		return (2);
	}
	if (fractal_type == 1)
		render_mandelbrot();
	else if (fractal_type == 2)
		render_julia();
	else if (fractal_type == 3)
		render_burning_ship();
	return (0);
}
