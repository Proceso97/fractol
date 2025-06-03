/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:00:00 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/05/28 18:00:00 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"      // Incluir tu libft
# include "../libft/ft_printf.h"  // Para ft_printf

# define WIDTH 800
# define HEIGHT 600

// Códigos de teclas
# define ESC_KEY    65307
# define CLOSE_WIN  17

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		max_iter;
}	t_data;

typedef enum e_fractal
{
	INVALID = 0,
	MANDELBROT = 1,
	JULIA = 2
}	t_fractal;

int		is_valid_fractal(char *name);
void	print_help(void);
void	render_mandelbrot(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

// Funciones de eventos
int		close_window(t_data *data);
int		key_handler(int keycode, t_data *data);
void	init_fractal_data(t_data *data);

// Funciones de renderizado
int		mandelbrot_iteration(double c_re, double c_im, int max_iter);
int		get_color(int iter, int max_iter);
void	draw_mandelbrot(t_data *data);

#endif


