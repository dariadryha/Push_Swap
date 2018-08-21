/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:54:55 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 16:54:56 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static	int	ft_check_integer(int n, char *str)
{
	char	*temp;
	int		res;

	temp = ft_itoa_base(n, 10);
	res = ft_strcmp(temp, str);
	free(temp);
	return (res ? 1 : 0);
}

static	int	ft_check_duble(int *mas, int temp, int i)
{
	int n;

	n = 0;
	while (n < i)
	{
		if (temp == mas[n])
			return (1);
		n++;
	}
	return (0);
}

void		ft_check_arg(int n, char **temp, t_stack **a)
{
	int mas[n];
	int i;

	i = 0;
	ft_bzero(mas, n * sizeof(int));
	while (i < n)
	{
		if ((temp[i][0] == '-' && ft_isdigit(temp[i][1])) ||
			ft_isdigit(temp[i][0]))
			mas[i] = ft_atoi(temp[i]);
		else
			ft_error();
		if (ft_check_integer(mas[i], temp[i]))
			ft_error();
		if (ft_check_duble(mas, mas[i], i))
			ft_error();
		i++;
	}
	*a = ft_fill_stack(mas, n, 'a');
}
