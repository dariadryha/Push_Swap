/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:41:47 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 14:41:47 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_del_stack(t_stack **head)
{
	t_stack *temp;
	t_stack *del;

	if (!head || !*head)
		return ;
	del = *head;
	while (del)
	{
		temp = del->next;
		del->data = 0;
		del->num = 0;
		del->c = '\0';
		del->next = NULL;
		free(del);
		del = temp;
	}
	*head = NULL;
}

t_stack		*ft_create_stack(int data, char a)
{
	t_stack *head;

	if (!(head = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	head->data = data;
	head->num = 0;
	head->c = a;
	head->next = NULL;
	return (head);
}

void		ft_add_end_stack(t_stack **head, int data, char a)
{
	t_stack *temp;

	if (!head || !*head)
		return ;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_create_stack(data, a);
}

t_stack		*ft_fill_stack(int *mas, int count, char a)
{
	t_stack		*head;
	int			i;

	i = 0;
	head = ft_create_stack(mas[i++], a);
	while (i < count)
		ft_add_end_stack(&head, mas[i++], a);
	return (head);
}
