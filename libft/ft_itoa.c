/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tswe-zin <tswe-zin@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:56:40 by tswe-zin@st       #+#    #+#             */
/*   Updated: 2025/06/12 05:47:59 by tswe-zin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	init_str(int n, int len, long *num, char **str)
{
	*str = malloc(len + 1);
	if (!*str)
		return (-1);
	(*str)[len--] = '\0';
	*num = n;
	if (n == 0)
	{
		(*str)[0] = '0';
		return (-1);
	}
	if (n < 0)
	{
		*num = -(long)n;
		(*str)[0] = '-';
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*str;

	len = int_len(n);
	len = init_str(n, len, &num, &str);
	if (len == -1)
		return (str);
	while (num > 0)
	{
		str[len--] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
