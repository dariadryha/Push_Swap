/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:52:13 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 14:52:13 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_find_num(t_stack *a, int mid)
{
	int flg;

	flg = a->num;
	while (a && (a->num == flg || !a->num))
	{
		if (a->c == 'a' && a->data < mid)
			return (1);
		if (a->c == 'b' && a->data > mid)
			return (1);
		a = a->next;
	}
	return (0);
}

static	void	ft_mid_push_b(t_stack **a, t_stack **b, int *i, unsigned int *n)
{
	while (ft_find_num(*a, i[0]))
	{
		if ((*a)->data <= i[0] && ++(*n))
			ft_rotate(a, (*a)->c);
		else
		{
			ft_push(a, b, (*b)->c);
			i[1]--;
		}
	}
}

static	void	ft_rotate_two_stack(t_stack **a, t_stack **b, int *i)
{
	while (ft_find_num(*a, i[0]))
	{
		if ((*a)->data >= i[0] && *b && (*b)->next &&
			(*b)->data < (*b)->next->data)
			ft_rotate_ab(a, b, 'r');
		else if ((*a)->data >= i[0])
			ft_rotate(a, (*a)->c);
		else
		{
			ft_push(a, b, 'b');
			i[1]--;
		}
	}
}

static	void	ft_mid_push_a(t_stack **a, t_stack **b, int *i, unsigned int *n)
{
	if (!(*a)->num && ft_check_reverse_stack(*a, i))
		ft_reverse_stack(a, b, i);
	else if (!(*a)->num && !*b)
		ft_rotate_two_stack(a, b, i);
	else
	{
		while (ft_find_num(*a, i[0]))
		{
			if ((*a)->num != 6 && (*a)->num != 4 &&
				(*a)->data >= i[0] && ++(*n))
				ft_rotate(a, (*a)->c);
			else if (((*a)->num == 6 || (*a)->num == 4)
				&& (*a)->data > i[0] && ++(*n))
				ft_rotate(a, (*a)->c);
			else
			{
				ft_push(a, b, 'b');
				i[1]--;
			}
		}
	}
}

void			ft_mid_stack(t_stack **a, t_stack **b, int *i, int count)
{
	unsigned int n;

	n = 0;
	if ((*a)->c == 'a' && (*a)->num != -1 && i[1] > 3)
		ft_mid_push_a(a, b, i, &n);
	if ((*a)->c == 'b')
		ft_mid_push_b(a, b, i, &n);
	if (!*b)
		return ;
	if ((*a)->c == 'b' || ((*a)->c == 'a' && ((*a)->num ||
		(!(*a)->num && i[1] <= 3))))
	{
		while (ft_check_num(*a, (*a)->num) && (*a)->num && n--)
			ft_reverse(a, (*a)->c);
		ft_set_num(a, i[1]);
	}
	ft_set_num(b, count - i[1]);
}
