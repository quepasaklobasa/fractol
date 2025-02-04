/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:40:05 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/04 15:04:54 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, t_range old, t_range new)
{
	return ((new.max - new.min) * (unscaled_num - old.min)
		/ (old.max - old.min) + new.min);
}

void	zoom_up(t_fractal *f, double zoom_f, double mouse_fx, double mouse_fy)
{
	f->zoom *= zoom_f;
	f->offset_x += (mouse_fx - f->offset_x) * (1 - 1 / zoom_f);
	f->offset_y += (mouse_fy - f->offset_y) * (1 - 1 / zoom_f);
}

void	zoom_down(t_fractal *f, double zoom_f, double mouse_fx, double mouse_fy)
{
	f->zoom /= zoom_f;
	f->offset_x -= (mouse_fx - f->offset_x) * (1 - zoom_f);
	f->offset_y -= (mouse_fy - f->offset_y) * (1 - zoom_f);
}
