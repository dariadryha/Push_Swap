/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:34:30 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 14:34:31 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **a, char c)
{
	int temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	c == 'a' || c == 'b' ? WR_S(c) : 0;
}

void	ft_swap_ab(t_stack **a, t_stack **b, char c)
{
	ft_swap(a, '\0');
	ft_swap(b, '\0');
	c == 's' ? WR_S(c) : 0;
}

void	ft_reverse(t_stack **a, char c)
{
	t_stack *temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *a;
	*a = temp->next;
	temp->next = NULL;
	c == 'a' || c == 'b' ? WR_RR(c) : 0;
}

void	ft_reverse_ab(t_stack **a, t_stack **b, char c)
{
	ft_reverse(a, '\0');
	ft_reverse(b, '\0');
	c == 'r' ? WR_RR(c) : 0;
}
