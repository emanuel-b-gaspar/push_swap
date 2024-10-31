/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:09:46 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:42:13 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}				t_list;

// VERIFS
int		ft_duplicate(t_list **a);
int		ft_desorganized(t_list **a);
int		ft_listsize(t_list **list);
int		ft_isempty(char *str);
int		check_empty_args(int ac, char **av);

// FREE && EXIT
void	ft_free_stack(t_list **a);
void	ft_exit_error(t_list **a);
void	free_matrix(char **matrix, int pos);

// SWAPS
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

// ROTATES
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

// REVESE ROTATES
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// PUSH
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

// SORTSMALL
void	ft_sort_small(t_list **a, t_list **b);

// MERGESORT
void	ft_merge_sort(t_list **a, t_list **b);

#endif
