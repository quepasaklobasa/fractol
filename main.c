/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:03:02 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/28 16:05:02 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
    {
        fractal.type = Mandelbrot;
    }
    else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5))
    {
        fractal.type = Julia;
        fractal.c_juliax = ft_atod(av[2]);
        fractal.c_juliay = ft_atod(av[3]);
    }
    else
    {
        ft_putendl_fd("Usage: ./fractol Mandelbrot\n       ./fractol Julia <real> <imaginary>", 2);
        return (1);
    }
    fractal_init(&fractal);
	fractal_render(&fractal);
    mlx_loop(fractal.mlx_connection);
    return (0);
}