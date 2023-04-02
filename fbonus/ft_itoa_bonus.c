/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pastilhex <pastilhex@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:17:24 by ialves-m          #+#    #+#             */
/*   Updated: 2023/04/02 18:12:46 by pastilhex        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_bonus.h"

int	counter(long int n)
{
	int	count;

	if (n <= 0)
	{
		n *= -1;
		count = 1;
	}
	else
		count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*str(char *newvalue, long int n, int count)
{
	long int	res;
	long int	inc;
	long int	back;

	inc = count;
	if (n <= 0)
	{
		n *= -1;
		newvalue[0] = '-';
	}
	back = n;
	res = n;
	newvalue[inc--] = '\0';
	while (res >= 10)
	{
		newvalue[inc--] = (res % 10) + 48;
		back /= 10;
		res = back;
	}
	newvalue[inc--] = res + 48;
	return (newvalue);
}

char	*ft_itoa_bonus(int n)
{
	char			*newvalue;
	char			*result;
	long int		nbr;

	nbr = n;
	newvalue = (char *)malloc(counter(nbr) * sizeof(char) + 1);
	if (!newvalue)
	{
		free (newvalue);
		return (0);
	}
	result = str(newvalue, nbr, (counter(nbr) * sizeof(char)));
	return (result);
}
