/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:03:02 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/03 17:45:38 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
		f.type = Mandelbrot;
	else if (ac == 2 && !ft_strncmp(av[1], "Tricorn", 7))
		f.type = Tricorn;
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5))
	{
		if (!check_number(av[2]) || !check_number(av[3]))
			error_message();
		f.type = Julia;
		f.c_jx = ft_atod(av[2]);
		f.c_jy = ft_atod(av[3]);
		if (f.c_jx < -2.0 || f.c_jx > 2.0 || f.c_jy < -2.0 || f.c_jy > 2.0)
			error_message();
	}
	else
		error_message();
	instructions();
	fractal_init(&f);
	fractal_render(&f);
	mlx_loop(f.mlx_connection);
	return (0);
}
