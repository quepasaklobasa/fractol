/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:59:05 by javi              #+#    #+#             */
/*   Updated: 2025/02/03 02:05:48 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_complex   complex_mult(t_complex a, t_complex b)
{
	t_complex	result;

	result.x = a.x * b.x - a.y * b.y;
	result.y = a.x * b.y + a.y * b.x;
	return (result);
}
t_complex	complex_div(t_complex a, t_complex b)
{
	t_complex	result;
	double		denominator;

	denominator = b.x * b.x + b.y * b.y;
	result.x = (a.x * b.x + a.y * b.y) / denominator;
	result.y = (a.y * b.x - a.x * b.y) / denominator;
	return (result);
}
t_complex	newton_method(t_complex z, t_fractal *f)
{
	t_complex	numerator;
	t_complex	denominator;
	t_complex	delta;
	int			iterations;

	iterations = 0;
	while (iterations < f->max_iterations)
	{
		numerator = complex_add(complex_add(complex_add(
						(t_complex){-1.0, 0.0}, complex_mult(z, z)),
					complex_mult(z, complex_mult(z, z))), (t_complex){0.0, 0.0});
		denominator = complex_add(complex_add((t_complex){0.0, 0.0},
					complex_mult((t_complex){2.0, 0.0}, z)),
				complex_mult((t_complex){3.0, 0.0}, complex_mult(z, z)));
		if (denominator.x == 0.0 && denominator.y == 0.0)
			break ;
		delta = complex_div(numerator, denominator);
		z = complex_add(z, (t_complex){-delta.x, -delta.y});
		if (complex_abs(delta) < f->newton_tolerance)
			break ;
		iterations++;
	}
	return (z);
}
