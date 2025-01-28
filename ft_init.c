/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:55:55 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/28 18:51:57 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		ft_putendl_fd("Error: mlx_init() failed", 2);
		exit(1);
	}
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, "Fractol");
	if (fractal->mlx_window == NULL)
	{
		ft_putendl_fd("Error: mlx_new_window() failed", 2);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		ft_putendl_fd("Error: mlx_new_image() failed", 2);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(1);
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);

}
void events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_press, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_window, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_press, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, mouse_move, fractal);
}

void data_init(t_fractal *fractal)
{
	if (fractal->type == Mandelbrot)
	{
		fractal->max_iterations = 42;
		fractal->zoom = 1.0;
		fractal->offset_x = -0.5;
		fractal->offset_y = 0.0;
		fractal->min.x = -2.0;
		fractal->min.y = -2.0;
		fractal->max.x = 2.0;
		fractal->max.y = 2.0;
		fractal->color_shift = PSYCHEDELIC_BLUE;
		fractal->color_cycle = BLACK;
	}
	else if (fractal->type == Julia)
	{
		fractal->max_iterations = 42;
		fractal->zoom = 1.0;
		fractal->offset_x = 0.0;
		fractal->offset_y = 0.0;
		fractal->min.x = -2.0;
		fractal->min.y = -2.0;
		fractal->max.x = 2.0;
		fractal->max.y = 2.0;
		fractal->color_shift = PSYCHEDELIC_BLUE;
		fractal->color_cycle = BLACK;
	}
}