/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:07:01 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/04 15:59:26 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*pixel;

	pixel = f->img.pixel_ptr + (y * f->img.line_len + x * (f->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

void	handle_pixel(t_fractal *f, int x, int y, int max_iterations)
{
	t_complex	c;
	t_complex	z;
	int			iterations;
	int			color;

	c.x = map(x, (t_range){0, WIDTH}, (t_range){f->min.x, f->max.x})
		* f->zoom + f->offset_x;
	c.y = map(y, (t_range){0, HEIGHT}, (t_range){f->min.y, f->max.y})
		* f->zoom + f->offset_y;
	iterations = 0;
	handle_fractal(f, &z, &c, x, y);
	while (iterations < max_iterations)
	{
		z = complex_add(complex_square(z), c);
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			color = get_color(iterations, f);
			ft_pixel_put(f, x, y, color);
			return ;
		}
		iterations++;
	}
	ft_pixel_put(f, x, y, BLACK);
}

void	fractal_render(t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(f, x, y, f->max_iterations);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_connection,
		f->mlx_window, f->img.img_ptr, 0, 0);
}

void	handle_fractal(t_fractal *f, t_complex *z, t_complex *c, int x, int y)
{
	if (f->type == Mandelbrot || f->type == Tricorn)
	{
		z->x = c->x;
		z->y = c->y;
	}
	else if (f->type == Julia)
	{
		z->x = map(x, (t_range){0, WIDTH}, (t_range){f->min.x, f->max.x})
			* f->zoom + f->offset_x;
		z->y = map(y, (t_range){0, HEIGHT}, (t_range){f->min.y, f->max.y})
			* f->zoom + f->offset_y;
		c->x = f->c_jx;
		c->y = f->c_jy;
	}
	if (f->type == Tricorn)
	{
		c->x = z->x;
		c->y = -z->y;
	}
}

void	update_max_iterations(t_fractal *f)
{
	f->max_iterations = (int)(42 + 50 * log(f->zoom + 1.0));
}