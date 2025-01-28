/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:06:41 by jcouto            #+#    #+#             */
/*   Updated: 2025/01/28 18:44:38 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color_palette (t_fractal *fractal)
{
    static int colors[] = {PSYCHEDELIC_BLUE, PSYCHEDELIC_CYAN, 
    PSYCHEDELIC_GREEN, PSYCHEDELIC_ORANGE, PSYCHEDELIC_TEAL, PSYCHEDELIC_LIME,
    PSYCHEDELIC_PINK, PSYCHEDELIC_PURPLE, PSYCHEDELIC_RED, PSYCHEDELIC_YELLOW};
    static int index = 0;

    fractal->color_shift = colors[index];
    index = (index + 1) % (sizeof(colors) / sizeof(colors[0]));
}

int cycle_color (t_fractal *fractal)
{
    static int colors[] = {BLACK, WHITE, RED, GREEN, BLUE};
    static int index = 0;

    fractal->color_cycle = colors[index];
    index = (index + 1) % (sizeof(colors) / sizeof(colors[0]));
}