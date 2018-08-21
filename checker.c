/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:19:06 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/24 20:19:07 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_after_inst(t_stack *a, t_stack *b, char *line)
{
	ft_printf(CYAN "٭ %s ٭ ------ˬˬˬ \n\n" RESET, line);
	ft_printf("Stack A : ");
	while (a)
	{
		ft_printf("%d ˘ ", a->data);
		a = a->next;
	}
	ft_printf("\n\nStack B : ");
	if (!b)
		ft_printf("EMPTY");
	while (b)
	{
		ft_printf("%d ˘ ", b->data);
		b = b->next;
	}
	ft_printf(PURPLE "\n----------------\n" RESET);
}

static	void	ft_read_data(t_stack **a, t_stack **b, int *flg)
{
	char			*line;
	unsigned int	res[SIZE];

	line = NULL;
	ft_bzero(res, SIZE * 4);
	if (ft_check_sorted(*a))
	{
		while ((get_next_line(0, &line)) > 0)
		{
			if (ft_valid_inst(line, a, b, res))
				ft_error();
			flg[5] ? ft_after_inst(*a, *b, line) : 0;
			free(line);
		}
	}
	ft_exec_flags(*a, flg, res);
	ft_check_sort(*a) && !*b ? ft_printf("OK\n") : ft_printf("KO\n");
}

static	void	ft_sev_arg(int i, int argc, char **argv, t_stack **a)
{
	if (!i)
		ft_check_arg(argc - 1, &argv[1], a);
	else
		ft_check_arg(argc - (i + 1), &argv[1 + i], a);
}

static	void	ft_one_arg(int i, char **argv, t_stack **a)
{
	char	**arr;
	int		count;

	count = 0;
	if (!i)
		arr = ft_strsplit(argv[1], ' ');
	else
		arr = ft_strsplit(argv[1 + i], ' ');
	while (arr[count])
		count++;
	ft_check_arg(count, arr, a);
	ft_del_mas_str(arr);
}

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		flg[FLG];
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	ft_bzero(flg, FLG * 4);
	if (argc > 1)
	{
		ft_search_flags(&argv[1], flg, &i);
		flg[3] || flg[4] || argc - i == 1 ? USAGE_CHECK : 0;
		if ((argc - i) == 2)
			ft_one_arg(i, argv, &a);
		else if (argc > 2)
			ft_sev_arg(i, argc, argv, &a);
		ft_read_data(&a, &b, flg);
		ft_del_stack(&a);
	}
	return (0);
}
