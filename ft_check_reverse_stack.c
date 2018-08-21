/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reverse_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:02:04 by ddryha            #+#    #+#             */
/*   Updated: 2018/03/06 15:02:05 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_stack(t_stack **a, t_stack **b, int *i)
{
	while (ft_find_num(*a, i[0]))
	{
		if ((*a)->data >= i[0])
			ft_reverse(a, (*a)->c);
		else
		{
			ft_push(a, b, 'b');
			i[1]--;
		}
	}
}

int		ft_check_reverse_stack(t_stack *a, int *i)
{
	int temp;
	int count;

	count = 0;
	temp = 0;
	while (a)
	{
		if (count >= i[1] / 2 && a->next &&
			a->data > a->next->data && a->data < i[0])
			temp++;
		count++;
		a = a->next;
	}
	if (temp >= ((i[1] / 2) - (i[1] / 2) / 4))
		return (1);
	return (0);
}
