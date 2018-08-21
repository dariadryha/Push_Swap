/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:22:00 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/24 20:22:00 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_count_median(t_stack **a, int *count)
{
	int		i[2];
	t_stack	*s;
	t_stack	*d;
	int		flg;

	s = *a;
	flg = s->num;
	while (s && (s->num == flg || !s->num))
	{
		ft_bzero(i, 2 * sizeof(int));
		d = *a;
		while (d && (d->num == flg || !d->num))
		{
			if (s->data < d->data)
				i[0]++;
			else
				i[1]++;
			d = d->next;
		}
		*count = !*count ? i[1] + i[0] : *count;
		if (i[0] == i[1] || i[0] == i[1] - 1)
			return (s->data);
		s = s->next;
	}
	return (0);
}

static	void	ft_make_decision(t_stack **a, t_stack **b, int *flg, int fd)
{
	if (*b && (*b)->c == 'a' && (*b)->num > 3)
		ft_sort_stack(b, a, flg, fd);
	else if (*b && (*b)->c == 'a' && ft_check_num(*b, (*b)->num) < 1)
		ft_apply_sorting(b, a, flg, fd);
	else if ((*a)->num > 3 || !(*a)->num)
		ft_sort_stack(a, b, flg, fd);
	else
		ft_apply_sorting(a, b, flg, fd);
}

static	void	ft_exec_flags_push(int flg, int mid, int fd)
{
	if (!flg)
	{
		ft_printf(CYAN "MEDIAN IS ---> " RESET);
		COLOR_D(CYAN, mid);
	}
	else
	{
		ft_putstr_fd("MEDIAN IS ---> ", fd);
		ft_putnbr_fd(mid, fd);
	}
}

void			ft_sort_stack(t_stack **a, t_stack **b, int *flg, int fd)
{
	int i[2];
	int count;

	count = 0;
	ft_bzero(i, 2 * sizeof(int));
	i[0] = ft_count_median(a, &count);
	if ((*a)->c == 'a' && !(*a)->num && !*b && !ft_check_sorted(*a))
		return ;
	if ((*a)->c == 'a' && !(*a)->num && count <= 3 && !*b)
	{
		ft_sort_three_block_a(a);
		return ;
	}
	i[1] = count;
	if (flg[4] && !flg[3])
		ft_exec_flags_push(flg[3], i[0], fd);
	if (flg[4] && flg[3])
		ft_exec_flags_push(flg[3], i[0], fd);
	ft_mid_stack(a, b, i, count);
	flg[3] && (*a)->num != -1 ? ft_debug_stack(*a, *b, fd) : 0;
	ft_make_decision(a, b, flg, fd);
}
