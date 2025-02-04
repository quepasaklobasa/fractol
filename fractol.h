/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:05:11 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/04 15:50:12 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800

# define ESC_KEY 65307
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define M_KEY 109
# define L_KEY 108
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define R_KEY 114
# define I_KEY 105
# define O_KEY 111
# define C_KEY 99
# define V_KEY 118

# define BLACK       0x000000  
# define WHITE       0xFFFFFF 
# define RED         0xFF0000 
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define PSYCHEDELIC_RED     0xFF4500 
# define PSYCHEDELIC_PINK    0xFF1493
# define PSYCHEDELIC_PURPLE  0x9400D3
# define PSYCHEDELIC_YELLOW  0xFFD700
# define PSYCHEDELIC_GREEN   0x7FFF00
# define PSYCHEDELIC_BLUE    0x1E90FF
# define PSYCHEDELIC_CYAN    0x00FFFF
# define PSYCHEDELIC_ORANGE  0xFF6347
# define PSYCHEDELIC_TEAL    0x008080
# define PSYCHEDELIC_LIME    0x32CD32

typedef enum e_fractal_type
{
	Mandelbrot,
	Julia,
	Tricorn
}	t_fractal_type;

typedef struct s_range
{
	double min;
	double max;
}	t_range;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	void			*mlx_connection;
	void			*mlx_window;
	t_img			img;
	t_complex		min;
	t_complex		max;
	t_fractal_type	type;
	int				max_iterations;
	int				x;
	int				y;
	double			zoom;
	double			offset_x;
	double			offset_y;
	double			c_jx;
	double			c_jy;
	double			mouse_x;
	double			mouse_y;
	int				color_shift;
	int				color_cycle;
}	t_fractal;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	fractal_init(t_fractal *fractal);
double	map(double unscaled_num, t_range old, t_range new);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
void	zoom_up(t_fractal *f, double zoom_factor, double mouse_fx, double mouse_fy);
void	zoom_down(t_fractal *f, double zoom_factor, double mouse_fx, double mouse_fy);
void	events_init(t_fractal *fractal);
void	data_init(t_fractal *fractal);
int		key_press(int keycode, t_fractal *fractal);
int		close_win(t_fractal *fractal);
int		mouse_press(int button, int x, int y, t_fractal *fractal);
void	ft_pixel_put(t_fractal *fractal, int x, int y, int color);
void	handle_pixel(t_fractal *fractal, int x, int y, int max_iterations);
void	fractal_render(t_fractal *fractal);
double	parse_integer_part(const char *str, int *i);
double	parse_decimal_part(const char *str, int *i);
double	ft_atod(const char *str);
int		mouse_move(int x, int y, t_fractal *fractal);
void	update_max_iterations(t_fractal *fractal);
int		cycle_color(t_fractal *fractal);
int		color_palette(t_fractal *fractal);
int		error_message(void);
void	instructions(void);
void	handle_fractal(t_fractal *fractal, t_complex *z, t_complex *c, int x, int y);
int		check_number(const char *str);
int		get_color(int iterations, t_fractal *fractal);

#endif