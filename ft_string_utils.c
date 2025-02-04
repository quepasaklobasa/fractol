/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcouto <jcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:30:12 by jcouto            #+#    #+#             */
/*   Updated: 2025/02/04 14:29:47 by jcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!s1 || !s2 || n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

double	parse_integer_part(const char *str, int *i)
{
	double	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

double	parse_decimal_part(const char *str, int *i)
{
	double	result;
	double	divisor;

	result = 0;
	divisor = 1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result = result * 10 + (str[*i] - '0');
			divisor *= 10;
			(*i)++;
		}
	}
	return (result / divisor);
}

double	ft_atod(const char *str)
{
	double	result;
	double	sign;
	int		i;

	if (!str)
		return (0);
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = parse_integer_part(str, &i);
	result += parse_decimal_part(str, &i);
	return (result * sign);
}
