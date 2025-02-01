/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:07:01 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/01 13:46:57 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_pixel_put(t_fractal *f, int x, int y, int color)
{
    char    *pixel;

    pixel = f->img.pixel_ptr + (y * f->img.line_len + x * (f->img.bpp / 8));
    *(unsigned int *)pixel = color;
}

void    handle_pixel(t_fractal *f, int x, int y, int max_iterations)
{
    t_complex c;
    t_complex z;
    int iterations;
    int color;

    iterations = 0;
    c.x = map(x, f->min.x, f->max.x, 0, WIDTH) * f->zoom + f->offset_x;
    c.y = map(y, f->min.y, f->max.y, 0, HEIGHT) * f->zoom + f->offset_y;

    if (f->type == Mandelbrot)
    {
        z.x = c.x;
        z.y = c.y;
    }
    else if (f->type == Julia)
    {
        z.x = map(x, f->min.x, f->max.x, 0, WIDTH) * f->zoom + f->offset_x;
        z.y = map(y, f->min.y, f->max.y, 0, HEIGHT) * f->zoom + f->offset_y;
        c.x = f->c_jx;
        c.y = f->c_jy;
    }

    while (iterations < max_iterations)
    {
        z = complex_add(complex_square(z), c);
        if ((z.x * z.x + z.y * z.y) > 4)
        {
            color = map(iterations, f->color_cycle, f->color_shift, 0, f->max_iterations);
            ft_pixel_put(f, x, y, color);
            return;
        }
        iterations++;
    }
    ft_pixel_put(f, x, y, BLACK);
}
void fractal_render(t_fractal *f)
{
    int x;
    int y;
    
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
    mlx_put_image_to_window(f->mlx_connection, f->mlx_window, f->img.img_ptr, 0, 0);
}
void update_max_iterations(t_fractal *f)
{
    f->max_iterations = (int)(42 + 50 * log(f->zoom + 1.0));
}