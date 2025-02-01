/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:06:48 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/30 17:48:37 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
	mlx_destroy_window(f->mlx_connection, f->mlx_window);
	mlx_destroy_display(f->mlx_connection);
	free(f->mlx_connection);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_fractal *f)
{
	if (keycode == ESC_KEY)
		close_window(f);
	else if (keycode == LEFT_ARROW)
		f->offset_x -= (.5 * f->zoom);
	else if (keycode == UP_ARROW)
		f->offset_y -= (.5 * f->zoom);
	else if (keycode == RIGHT_ARROW)
		f->offset_x += (.5 * f->zoom);
	else if (keycode == DOWN_ARROW)
		f->offset_y += (.5 * f->zoom);
	else if (keycode == M_KEY)
		f->max_iterations += 10;
	else if (keycode == L_KEY)
		f->max_iterations -= 10;
	else if (keycode == R_KEY)
		data_init(f);
	else if (keycode == C_KEY)
		cycle_color(f);
	else if (keycode == V_KEY)
		color_palette(f);
	fractal_render(f);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractal *f)
{
	double	zoom_factor;
	double	mouse_fractal_x;
	double	mouse_fractal_y;

	mouse_fractal_x = map(x, f->min.x, f->max.x, 0, WIDTH);
	mouse_fractal_y = map(y, f->min.y, f->max.y, 0, HEIGHT);
	zoom_factor = 1.1;
	if (button == SCROLL_DOWN)
	{
		f->zoom *= zoom_factor;
		f->offset_x += (mouse_fractal_x - f->offset_x) * (1 - 1 / zoom_factor);
		f->offset_y += (mouse_fractal_y - f->offset_y) * (1 - 1 / zoom_factor);
	}
	else if (button == SCROLL_UP)
	{
		f->zoom /= zoom_factor;
		f->offset_x -= (mouse_fractal_x - f->offset_x) * (1 - zoom_factor);
		f->offset_y -= (mouse_fractal_y - f->offset_y) * (1 - zoom_factor);
	}
	update_max_iterations(f);
	fractal_render(f);
	return (0);
}

int	mouse_move(int x, int y, t_fractal *f)
{
	static int	last_x = -1, last_y = -1;

	if (f->type == Julia && (abs(x - last_x) > 7 || abs(y - last_y) > 7))
	{
		f->c_jx = map(x, f->min.x, f->max.x, 0, WIDTH) * f->zoom + f->offset_x;
		f->c_jy = map(y, f->min.y, f->max.y, 0, HEIGHT) * f->zoom + f->offset_y;
		fractal_render(f);
		last_x = x;
		last_y = y;
	}
	return (0);
}
