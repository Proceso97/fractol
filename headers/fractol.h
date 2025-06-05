/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:00:00 by jzarza-g          #+#    #+#             */
/*   Updated: 2025/06/05 15:00:00 by jzarza-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# define WIDTH 800
# define HEIGHT 600

// Códigos de teclas
# define ESC_KEY    65307
# define CLOSE_WIN  17

// Códigos de ratón
# define MOUSE_WHEEL_UP    4
# define MOUSE_WHEEL_DOWN  5

// Códigos de teclas adicionales
# define ARROW_LEFT   65361
# define ARROW_RIGHT  65363
# define ARROW_UP     65362
# define ARROW_DOWN   65364

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
	int		fractal_type;
	double	julia_c_re;
	double	julia_c_im;
}	t_data;

typedef enum e_fractal
{
	INVALID = 0,
	MANDELBROT = 1,
	JULIA = 2,
	BURNING_SHIP = 3
}	t_fractal;

// Funciones principales
int		is_valid_fractal(char *name);
void	print_help(void);

// Funciones de renderizado principal
void	render_mandelbrot(void);
void	render_julia(void);
void	render_burning_ship(void);

// Funciones de utilidades gráficas
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_color(int iter, int max_iter);

// Funciones de inicialización
void	init_fractal_data(t_data *data);
void	init_julia_data(t_data *data);
void	init_burning_ship_data(t_data *data);

// Funciones de algoritmos matemáticos
int		mandelbrot_iteration(double c_re, double c_im, int max_iter);
int		julia_iteration(double z_re, double z_im, t_data *data);
int		burning_ship_iteration(double c_re, double c_im, int max_iter);

// Funciones de dibujo
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	draw_burning_ship(t_data *data);
void	redraw_fractal(t_data *data);

// Funciones de eventos
int		close_window(t_data *data);
int		key_handler(int keycode, t_data *data);
int		mouse_handler(int button, int x, int y, t_data *data);
void	move_view(t_data *data, double move_re, double move_im);

// Funciones de zoom
void	zoom(t_data *data, int x, int y, double zoom_factor);

#endif
