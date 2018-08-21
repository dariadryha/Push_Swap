/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:28:24 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/24 19:28:24 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_print_res_inst(unsigned int *res)
{
	unsigned int i;

	i = 0;
	while (i < SIZE)
	{
		if (res[i] && (!i || i == 1))
			!i ? COLOR_S(BLUE, RA) : COLOR_S(PURPLE, RB);
		if (res[i] && (i == 2 || i == 3))
			i == 2 ? COLOR_S(CYAN, SA) : COLOR_S(YELLOW, SB);
		if (res[i] && (i == 4 || i == 5))
			i == 4 ? COLOR_S(BLUE, SS) : COLOR_S(PURPLE, RR);
		if (res[i] && (i == 6 || i == 7))
			i == 6 ? COLOR_S(CYAN, PA) : COLOR_S(YELLOW, PB);
		if (res[i] && (i == 8 || i == 9))
			i == 8 ? COLOR_SR(BLUE, RRA) : COLOR_SR(PURPLE, RRB);
		if (res[i] && i == 10)
			COLOR_SR(CYAN, RRR);
		res[i] ? COLOR_D(GREEN, res[i]) : 0;
		i++;
	}
}

static	void	ft_print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d\n", a->data);
		a = a->next;
	}
}

static	void	ft_count_inst(unsigned int *res)
{
	int i;

	i = 0;
	while (i < SIZE - 1)
		res[11] += res[i++];
}

void			ft_exec_flags(t_stack *a, int *flg, unsigned int *res)
{
	flg[0] ? ft_print_stack(a) : 0;
	flg[1] ? ft_print_res_inst(res) : 0;
	if (flg[2])
	{
		ft_count_inst(res);
		ft_printf(RED"  SUM IS:  \n---> %d <---\n" RESET, res[11]);
	}
}
