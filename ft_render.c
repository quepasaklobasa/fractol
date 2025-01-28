/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:07:01 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/28 18:45:14 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_pixel_put(t_fractal *fractal, int x, int y, int color)
{
    char *pixel;

    pixel = fractal->img.pixel_ptr + (y * fractal->img.line_len + x * (fractal->img.bpp / 8));
    *(unsigned int *)pixel = color;
}
void handle_pixel(t_fractal *fractal, int x, int y, int max_iterations)
{
    t_complex c;
    t_complex z;
    int iterations;
    int color;

    iterations = 0;
    c.x = map(x, fractal->min.x, fractal->max.x, 0, WIDTH) * fractal->zoom + fractal->offset_x;
    c.y = map(y, fractal->min.y, fractal->max.y, 0, HEIGHT) * fractal->zoom + fractal->offset_y;

    if (fractal->type == Mandelbrot)
    {
        z.x = c.x;
        z.y = c.y;
    }
    else if (fractal->type == Julia)
    {
        z.x = map(x, fractal->min.x, fractal->max.x, 0, WIDTH) * fractal->zoom + fractal->offset_x;
        z.y = map(y, fractal->min.y, fractal->max.y, 0, HEIGHT) * fractal->zoom + fractal->offset_y;
        c.x = fractal->c_juliax;
        c.y = fractal->c_juliay;
    }

    while (iterations < fractal->max_iterations)
    {
        z = complex_add(complex_square(z), c);
        if ((z.x * z.x + z.y * z.y) > 4)
        {
            color = map(iterations, fractal->color_cycle, fractal->color_shift, 0, fractal->max_iterations);
            ft_pixel_put(fractal, x, y, color);
            return;
        }
        iterations++;
    }
    ft_pixel_put(fractal, x, y, BLACK);
}
void fractal_render(t_fractal *fractal)
{
    int x;
    int y;
    
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handle_pixel(fractal, x, y, fractal->max_iterations);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
void update_max_iterations(t_fractal *fractal)
{
    fractal->max_iterations = (int)(42 + 50 * log(fractal->zoom + 1.0));
}