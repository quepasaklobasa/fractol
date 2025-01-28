/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:06:48 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/28 19:54:03 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(0);
    return(0);
}

int key_press(int keycode, t_fractal *fractal)
{
    if (keycode == ESC_KEY)
        close_window(fractal);
    else if (keycode == LEFT_ARROW)
        fractal->offset_x -= (.5 * fractal->zoom);
    else if (keycode == UP_ARROW)
        fractal->offset_y -= (.5 * fractal->zoom);
    else if (keycode == RIGHT_ARROW)
        fractal->offset_x += (.5 * fractal->zoom);
    else if (keycode == DOWN_ARROW)
        fractal->offset_y += (.5 * fractal->zoom);
    else if (keycode == M_KEY)
        fractal->max_iterations += 10;
    else if (keycode == L_KEY)
        fractal->max_iterations -= 10;
    else if (keycode == R_KEY)
            data_init(fractal);
    else if (keycode == C_KEY)
            cycle_color(fractal);
    else if (keycode == V_KEY)
            color_palette(fractal);
    fractal_render(fractal);
    return (0);
}

int mouse_press(int button, int x, int y, t_fractal *fractal)
{
    double zoom_factor = 1.1;
    double mouse_fractal_x = map(x, fractal->min.x, fractal->max.x, 0, WIDTH);
    double mouse_fractal_y = map(y, fractal->min.y, fractal->max.y, 0, HEIGHT);

    if (button == SCROLL_DOWN)
    {
        fractal->zoom *= zoom_factor;
        fractal->offset_x += (mouse_fractal_x - fractal->offset_x) * (1 - 1 / zoom_factor);
        fractal->offset_y += (mouse_fractal_y - fractal->offset_y) * (1 - 1 / zoom_factor);
    }
    else if (button == SCROLL_UP)
    {
        fractal->zoom /= zoom_factor;
        fractal->offset_x -= (mouse_fractal_x - fractal->offset_x) * (1 - zoom_factor);
        fractal->offset_y -= (mouse_fractal_y - fractal->offset_y) * (1 - zoom_factor);
    }
    update_max_iterations(fractal);
    fractal_render(fractal);
    return (0);
}

int mouse_move(int x, int y, t_fractal *fractal)
{
    static int last_x = -1, last_y = -1;

    if (fractal->type == Julia && (abs(x - last_x) > 7 || abs(y - last_y) > 7))
    {
        fractal->c_juliax = map(x, fractal->min.x, fractal->max.x, 0, WIDTH) * fractal->zoom + fractal->offset_x;
        fractal->c_juliay = map(y, fractal->min.y, fractal->max.y, 0, HEIGHT) * fractal->zoom + fractal->offset_y;
        fractal_render(fractal);
        last_x = x;
        last_y = y;
    }
    return (0);
}