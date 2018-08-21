/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:07:00 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 16:07:00 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_sorting_block(t_stack **a)
{
	while (ft_check_sorted(*a))
	{
		if ((*a)->next && (*a)->data > (*a)->next->data)
			ft_swap(a, (*a)->c);
		if (!(ft_check_sorted(*a)))
			break ;
		ft_rotate(a, (*a)->c);
		if ((*a)->data > (*a)->next->data)
			ft_swap(a, (*a)->c);
		else
			break ;
		ft_reverse(a, (*a)->c);
	}
}

static	void	ft_find_max(t_stack **a, t_stack **b)
{
	t_stack		*l;
	int			temp;
	int			flg;

	temp = (*b)->data;
	flg = (*b)->num;
	l = (*b)->next;
	while (l && l->num == flg)
	{
		if (temp < l->data)
			return ;
		l = l->next;
	}
	ft_push(b, a, (*a)->c);
	(*a)->num = -1;
	ft_set_num(b, (*b)->num - 1);
}

static int		ft_add_from_b(t_stack **a, t_stack **b, int flg)
{
	if (*b && (*b)->num <= 3 && (*b)->num != -1)
	{
		while (flg--)
		{
			if ((*a)->c == 'a' && (*a)->num != -1 && (*a)->next &&
				(*a)->data > (*a)->next->data)
				ft_swap(a, (*a)->c);
			ft_push(b, a, (*a)->c);
			if ((*a)->num == 3 && *b && (*b)->next &&
				(*b)->next->data > (*a)->data &&
				(*b)->next->data > (*b)->data)
				ft_swap(b, (*b)->c);
			if (*b)
				(*b)->num = !flg ? (*b)->num : (*a)->num;
		}
		return (1);
	}
	if ((*a)->c == 'a' && *b)
		ft_find_max(a, b);
	return (0);
}

void			ft_apply_sorting(t_stack **a, t_stack **b, int *mas,
	int fd)
{
	int flg;

	flg = (*a) ? (*a)->num : 0;
	if ((*a)->c == 'a' && *b)
		ft_sort_together(a, b);
	if ((*a)->c == 'a' && !ft_check_num(*a, (*a)->num))
		ft_sort_three_block_a(a);
	if ((*a)->c == 'a')
	{
		ft_sorting_block(a);
		(*a)->num = (*a)->c == 'a' ? -1 : flg;
	}
	flg = (*b) ? (*b)->num : 0;
	if (*b && (*b)->c == 'a' && (*b)->num <= 3 && (*b)->num != -1)
	{
		if (ft_check_num(*b, flg) == -1)
			ft_apply_sorting(b, a, mas, fd);
	}
	if (ft_add_from_b(a, b, flg))
		ft_apply_sorting(a, b, mas, fd);
	if (!(*b) && (*a)->c == 'a')
		return ;
	ft_sort_stack(b, a, mas, fd);
}
