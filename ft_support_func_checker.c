/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_func_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:55:43 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/24 19:55:44 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_usage_checker(void)
{
	ft_printf("Usage: ./checker [-v | -n | -s | -e] path\n");
	ft_printf("-s  display the total number of instructions ./push_swap\n");
	ft_printf("-n  display the number of each operations ./push_swap\n");
	ft_printf("-v  display the stack a\n");
	exit(EXIT_FAILURE);
}

int		ft_check_sorted(t_stack *a)
{
	while (a && a->num != -1)
	{
		if (a->c == 'a' && a->next && a->data > a->next->data)
			return (1);
		if (a->c == 'b' && a->next && a->data < a->next->data)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_search_flags(char **temp, int *flg, int *x)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i][0] == '-' && !ft_isdigit(temp[i][1]) && !temp[i][2])
		{
			if (temp[i][1] == 'v')
				flg[0] ? USAGE_CHECK : flg[0]++;
			if (temp[i][1] == 'n')
				flg[1] ? USAGE_CHECK : flg[1]++;
			if (temp[i][1] == 's')
				flg[2] ? USAGE_CHECK : flg[2]++;
			if (temp[i][1] == 'd')
				flg[3] ? USAGE_PS : flg[3]++;
			if (temp[i][1] == 'm')
				flg[4] ? USAGE_PS : flg[4]++;
			if (temp[i][1] == 'l')
				flg[5] ? USAGE_CHECK : flg[5]++;
		}
		else
			break ;
		i++;
	}
	*x = flg[0] + flg[1] + flg[2] + flg[3] + flg[4] + flg[5];
}
