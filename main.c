/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:03:02 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/30 17:50:18 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char **av)
{
	t_fractal	f;

	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
    {
        f.type = Mandelbrot;
    }
    else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5))
    {
        f.type = Julia;
        f.c_jx = ft_atod(av[2]);
        f.c_jy = ft_atod(av[3]);
    }
    else
    {
        ft_putendl_fd("Usage: ./fractol Mandelbrot\n       ./fractol Julia <real> <imaginary>", 2);
        return (1);
    }
    fractal_init(&f);
	fractal_render(&f);
    mlx_loop(f.mlx_connection);
    return (0);
}