/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:59:23 by ddryha            #+#    #+#             */
/*   Updated: 2018/02/24 19:59:24 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RA "ra"
# define RB "rb"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define RR "rr"
# define PA "pa"
# define PB "pb"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# define SIZE 12
# define FLG 6

# define USAGE_CHECK ft_usage_checker()
# define USAGE_PS ft_usage_push_swap()
# define CHECK(x, y) (!(ft_strcmp(x, y)) ? 0 : 1)
# define COLOR_S(x, y) (ft_printf(x "--->%-7s" RESET, y))
# define COLOR_SR(x, y) (ft_printf(x "--->%-7s" RESET, y))
# define COLOR_D(x, y) (ft_printf(x "%d\n" RESET, y))
# define WR_S(x) ft_printf("s%c\n", x)
# define WR_R(x) ft_printf("r%c\n", x)
# define WR_RR(x) ft_printf("rr%c\n", x)
# define WR_P(x) ft_printf("p%c\n", x)

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>

typedef	struct		s_stack
{
	int				data;
	char			c;
	int				num;
	struct s_stack	*next;
}					t_stack;

void				ft_error(void);
void				ft_sort_stack(t_stack **a, t_stack **b, int *flg,
	int fd);
void				ft_search_flags(char **temp, int *flg, int *x);
void				ft_usage_checker(void);
void				ft_usage_push_swap(void);
void				ft_exec_flags(t_stack *a, int *flg, unsigned int *res);
int					ft_valid_inst(char *line, t_stack **a, t_stack **b,
	unsigned int *res);
int					ft_check_sort(t_stack *a);
void				ft_check_arg(int n, char **temp, t_stack **a);
t_stack				*ft_create_stack(int data, char a);
void				ft_add_end_stack(t_stack **head, int data, char a);
void				ft_del_stack(t_stack **head);
t_stack				*ft_fill_stack(int *mas, int count, char a);
void				ft_swap_ab(t_stack **a, t_stack **b, char c);
void				ft_swap(t_stack **a, char c);
void				ft_push(t_stack **a, t_stack **b, char c);
void				ft_rotate(t_stack **a, char c);
void				ft_rotate_ab(t_stack **a, t_stack **b, char c);
void				ft_reverse(t_stack **a, char c);
void				ft_reverse_ab(t_stack **a, t_stack **b, char c);
void				ft_mid_stack(t_stack **a, t_stack **b, int *i, int count);
void				ft_apply_sorting(t_stack **a, t_stack **b, int *flg,
	int fd);
int					ft_check_num(t_stack *a, int ord);
void				ft_sort_three_block_a(t_stack **a);
void				ft_sort_together(t_stack **a, t_stack **b);
int					ft_check_sorted(t_stack *a);
void				ft_debug_stack(t_stack *a, t_stack *b, int fd);
void				ft_set_num(t_stack **b, int m);
int					ft_find_num(t_stack *a, int mid);
int					ft_check_reverse_stack(t_stack *a, int *i);
void				ft_reverse_stack(t_stack **a, t_stack **b, int *i);

#endif
