/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:38:57 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 14:38:57 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*new;

	if (!a || !*a)
		return ;
	new = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	(*b)->c = c;
	*a = new;
	c == 'a' || c == 'b' ? WR_P(c) : 0;
}

void	ft_rotate(t_stack **a, char c)
{
	t_stack *temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = *a;
	*a = (*a)->next;
	temp->next->next = NULL;
	c == 'a' || c == 'b' ? WR_R(c) : 0;
}

void	ft_rotate_ab(t_stack **a, t_stack **b, char c)
{
	ft_rotate(a, '\0');
	ft_rotate(b, '\0');
	c == 'r' ? WR_R(c) : 0;
}
