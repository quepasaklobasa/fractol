/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:33:03 by javi              #+#    #+#             */
/*   Updated: 2025/02/03 17:42:08 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_message(void)
{
	ft_putendl_fd("Usage: ./fractol [Mandelbrot | Tricorn]", 2);
	ft_putendl_fd("./fractol Julia [X] [Y]", 2);
	ft_putendl_fd("X and Y values must be between -2 and 2.", 2);
	exit(1);
}

void	instructions(void)
{
	ft_putendl_fd("Instructions:", 1);
	ft_putendl_fd("Zoom: Mouse wheel", 1);
	ft_putendl_fd("Move: Arrows", 1);
	ft_putendl_fd("Change color: C", 1);
	ft_putendl_fd("Change color palette: V", 1);
	ft_putendl_fd("Increase max iterations: M", 1);
	ft_putendl_fd("Decrease max iterations: L", 1);
	ft_putendl_fd("Reset: R", 1);
	ft_putendl_fd("Exit: ESC", 1);
}
