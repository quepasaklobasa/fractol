/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:55:55 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/04 15:58:26 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *f)
{
	f->mlx_connection = mlx_init();
	if (f->mlx_connection == NULL)
	{
		exit(1);
	}
	f->mlx_window = mlx_new_window(f->mlx_connection, WIDTH, HEIGHT, "Fractol");
	if (f->mlx_window == NULL)
	{
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		exit(1);
	}
	f->img.img_ptr = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_window(f->mlx_connection, f->mlx_window);
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		exit(1);
	}
	f->img.pixel_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
	events_init(f);
	data_init(f);
}

void	events_init(t_fractal *f)
{
	mlx_hook(f->mlx_window, KeyPress, KeyPressMask, key_press, f);
	mlx_hook(f->mlx_window, DestroyNotify, StructureNotifyMask, close_win, f);
	mlx_hook(f->mlx_window, ButtonPress, ButtonPressMask, mouse_press, f);
	mlx_hook(f->mlx_window, MotionNotify, PointerMotionMask, mouse_move, f);
}

void	data_init(t_fractal *f)
{
	f->max_iterations = 42;
	f->zoom = 1.0;
	f->offset_x = -0.5;
	f->offset_y = 0.0;
	f->x = 0;
	f->y = 0;
	f->min.x = -2.0;
	f->min.y = -2.0;
	f->max.x = 2.0;
	f->max.y = 2.0;
	f->color_shift = PSYCHEDELIC_BLUE;
	f->color_cycle = BLACK;
	if (f->type == Julia)
		f->offset_x = 0.0;
	f->c_jx = -0.7;
	f->c_jy = 0.27015;
}
