/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:48:41 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/26 14:48:41 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack		*a;
	t_stack		*b;
	int			flg[FLG];
	int			i;
	int			fd;

	a = NULL;
	b = NULL;
	i = 0;
	ft_bzero(flg, FLG * sizeof(int));
	if (argc == 1)
		USAGE_PS;
	ft_search_flags(&argv[1], flg, &i);
	if (flg[0] || flg[1] || flg[2] || flg[5])
		USAGE_PS;
	fd = flg[3] ? open("debug.txt", O_RDWR | O_TRUNC | O_CREAT, 0777) : 0;
	if ((argc == 2 && !i) || (argc - i) == 2)
		ft_one_arg(i, argv, &a);
	else if (argc > 2)
		ft_sev_arg(i, argc, argv, &a);
	if (argc - i == 1)
		USAGE_PS;
	ft_sort_stack(&a, &b, flg, fd);
	ft_del_stack(&a);
	return (0);
}
