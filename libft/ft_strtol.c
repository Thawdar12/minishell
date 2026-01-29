/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:29:27 by tswe-zin          #+#    #+#             */
/*   Updated: 2025/11/11 18:11:26 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*handle_sign(const char *p, int *sign)
{
	if (*p == '-')
	{
		*sign = -1;
		p++;
	}
	else if (*p == '+')
		p++;
	return (p);
}

static const char	*handle_base(const char *p, int *base)
{
	if (*base == 0)
	{
		if (*p == '0')
		{
			if (p[1] == 'x' || p[1] == 'X')
			{
				*base = 16;
				p += 2;
			}
			else
			{
				*base = 8;
				p++;
			}
		}
		else
			*base = 10;
	}
	return (p);
}

static long	convert_digits(const char *p, char **endptr, int base)
{
	long	result;
	int		digit;

	result = 0;
	while (*p)
	{
		if (ft_isdigit((unsigned char)*p))
			digit = *p - '0';
		else if (*p >= 'a' && *p <= 'z')
			digit = *p - 'a' + 10;
		else if (*p >= 'A' && *p <= 'Z')
			digit = *p - 'A' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		p++;
	}
	if (endptr)
		*endptr = (char *)p;
	return (result);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	const char	*p;
	long		result;
	int			sign;

	p = str;
	sign = 1;
	while (ft_isspace((unsigned char)*p))
		p++;
	p = handle_sign(p, &sign);
	p = handle_base(p, &base);
	result = convert_digits(p, endptr, base);
	return (sign * result);
}
