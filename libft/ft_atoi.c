/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:04:27 by smishos           #+#    #+#             */
/*   Updated: 2024/04/29 12:34:14 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	ret;
	long	check;

	i = 0;
	sign = 1;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = ret; //assign check
		ret = (ret * 10) + (str[i++] - 48); //number grows bigger
		//check if check bigger than ret (ret should always be bigger until max_long overflow)
		if (check > ret && sign == 1)
			return (-1);
		if (check > ret && sign == -1)
			return (0);
	}
	return ((int)(ret * sign));
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	main()
{
	char *str = "-9223372136854775819";
	while (*str)
	{
	printf("%d\n", ft_atoi(str));
	printf("%d\n\n", atoi(str));
	str++;
	}
	return (0);
}
