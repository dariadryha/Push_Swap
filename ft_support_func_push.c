/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_func_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:37:17 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/28 12:37:17 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_debug_stack(t_stack *a, t_stack *b, int fd)
{
	ft_putstr_fd("\nSTACK A - [ ", fd);
	ft_putchar_fd(a->c, fd);
	ft_putstr_fd(" ] ---> ", fd);
	while (a)
	{
		ft_putnbr_fd(a->data, fd);
		ft_putstr_fd(" ˘ ", fd);
		a = a->next;
	}
	ft_putstr_fd("\n\nSTACK B - [ ", fd);
	ft_putchar_fd(b->c, fd);
	ft_putstr_fd(" ] ---> ", fd);
	while (b)
	{
		ft_putnbr_fd(b->data, fd);
		ft_putstr_fd(" ˘ ", fd);
		b = b->next;
	}
	ft_putstr_fd("\n\n", fd);
}

void	ft_usage_push_swap(void)
{
	ft_printf("Usage: ./push_swap [-m] path\n");
	ft_printf("-m  display the median\n");
	ft_printf("-d  display stack a and stack b after median division\n");
	exit(EXIT_FAILURE);
}

void	ft_set_num(t_stack **b, int m)
{
	t_stack		*temp;
	int			flg;

	temp = *b;
	flg = m;
	while (temp && m--)
	{
		temp->num = flg;
		temp = temp->next;
	}
}

int		ft_check_num(t_stack *a, int flg)
{
	int i;

	i = 0;
	while (a && i++ < flg)
		a = a->next;
	if (a && a->num == -1)
		return (-1);
	else if (a && a->num > 0)
		return (a->num);
	else
		return (0);
}

void	ft_sort_three_block_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->next->next)
	{
		if ((*a)->next->data > (*a)->data &&
			(*a)->next->data > (*a)->next->next->data)
			ft_reverse(a, (*a)->c);
		if ((*a)->data > (*a)->next->data &&
			(*a)->data > (*a)->next->next->data)
			ft_rotate(a, (*a)->c);
	}
	if ((*a)->data > (*a)->next->data)
		ft_swap(a, (*a)->c);
}
