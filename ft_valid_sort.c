/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:13:50 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/24 20:13:51 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sort(t_stack *a)
{
	while (a)
	{
		if ((a->next && a->data < a->next->data) || !a->next)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int		ft_valid_inst(char *line, t_stack **a, t_stack **b,
	unsigned int *res)
{
	if (!(CHECK(line, RA)) && ++(res[0]))
		ft_rotate(a, '\0');
	else if (!(CHECK(line, RB)) && ++(res[1]))
		ft_rotate(b, '\0');
	else if (!(CHECK(line, SA)) && ++(res[2]))
		ft_swap(a, '\0');
	else if (!(CHECK(line, SB)) && ++(res[3]))
		ft_swap(b, '\0');
	else if (!(CHECK(line, SS)) && ++(res[4]))
		ft_swap_ab(a, b, '\0');
	else if (!(CHECK(line, RR)) && ++(res[5]))
		ft_rotate_ab(a, b, '\0');
	else if (!(CHECK(line, PA)) && ++(res[6]))
		ft_push(b, a, '\0');
	else if (!(CHECK(line, PB)) && ++(res[7]))
		ft_push(a, b, '\0');
	else if (!(CHECK(line, RRA)) && ++(res[8]))
		ft_reverse(a, '\0');
	else if (!(CHECK(line, RRB)) && ++(res[9]))
		ft_reverse(b, '\0');
	else if (!(CHECK(line, RRR)) && ++(res[10]))
		ft_reverse_ab(a, b, '\0');
	else
		return (1);
	return (0);
}
