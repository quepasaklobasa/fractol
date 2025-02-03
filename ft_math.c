/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:06:57 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/03 19:04:59 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_complex	complex_square(t_complex a)
{
	t_complex	result;

	result.x = (a.x * a.x) - (a.y * a.y);
	result.y = 2 * a.x * a.y;
	return (result);
}

int	check_number(const char *str)
{
	int	i;
	int	decimal;

	i = 0;
	decimal = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			decimal++;
			if (decimal > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '.')))
		return (0);
	return (1);
}
