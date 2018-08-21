/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_together.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:21:21 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/28 12:21:21 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_sort_three_together(t_stack **a, t_stack **b)
{
	if (((*a)->data > (*a)->next->data &&
		(*a)->data > (*a)->next->next->data) &&
	((*b)->next->next->data > (*b)->data &&
		(*b)->next->next->data > (*b)->next->data))
		ft_swap_ab(a, b, 's');
	ft_rotate_ab(a, b, 'r');
	ft_swap_ab(a, b, 's');
	ft_reverse_ab(a, b, 'r');
	if ((*a)->data > (*a)->next->data && (*b)->data < (*b)->next->data)
		ft_swap_ab(a, b, 's');
}

void			ft_sort_together(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !*b || !(*a)->next || !(*b)->next)
		return ;
	if (!ft_check_sorted(*a) || !ft_check_sorted(*b))
		return ;
	if ((*a)->num == 3 && (*b)->num == 3)
	{
		if (((*a)->next->data > (*a)->data &&
			(*a)->next->data > (*a)->next->next->data) &&
			((*b)->next->data < (*b)->data) &&
			(*b)->next->data < (*b)->next->next->data)
			ft_sort_three_together(a, b);
		else if (((*a)->data > (*a)->next->data &&
			(*a)->data > (*a)->next->next->data) &&
			((*b)->next->next->data > (*b)->data &&
				(*b)->next->next->data > (*b)->next->data))
			ft_sort_three_together(a, b);
	}
	else if (((*a)->num == 3 && (*b)->num == 2) ||
		((*a)->num == 2 && (*b)->num == 3))
	{
		if ((*a)->data > (*a)->next->data && (*b)->data < (*b)->next->data)
			ft_swap_ab(a, b, 's');
	}
	else if ((*a)->data > (*a)->next->data && (*b)->data < (*b)->next->data)
		ft_swap_ab(a, b, 's');
}
