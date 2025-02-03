/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:33:03 by javi              #+#    #+#             */
/*   Updated: 2025/02/03 03:11:38 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int error_message(void)
{
    ft_putendl_fd("Usage: ./fractol [Mandelbrot | Julia [c_re c_im]]", 2);
    ft_putendl_fd("c_re and c_im must be between -2 and 2.", 2);
    exit(1);
}

void instructions(void)
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
int check_number(const char *str)
{
    int i = 0;
    int decimal = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] == '.')
        {
            decimal++;
            if (decimal > 1)
                return 0;
        }
        else if (str[i] < '0' || str[i] > '9')
                return 0;
        i++;
    }
    if (i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '.')))
        return 0;
    return 1;
}