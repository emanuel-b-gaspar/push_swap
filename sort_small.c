/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:13:36 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:24:33 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_sort_three(t_list **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		ra(a);
	else if ((*a)->next->value > (*a)->value
		&& (*a)->next->value > (*a)->next->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

int	ft_find_small(t_list **a)
{
	int			i;
	int			small;
	int			index;
	t_list		*tmp;

	i = 0;
	index = 0;
	tmp = *a;
	small = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < small)
		{
			index = i;
			small = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}

void	ft_selection_sort(t_list **a, t_list **b)
{
	int	small_index;

	while (ft_listsize(a) > 3)
	{
		small_index = ft_find_small(a);
		while (small_index > 0)
		{
			if (small_index == ft_listsize(a) - 1)
			{
				rra(a);
				break ;
			}
			ra(a);
			small_index--;
		}
		pb(a, b);
	}
}

void	ft_sort_small(t_list **a, t_list **b)
{
	ft_selection_sort(a, b);
	ft_sort_three(a);
	while (ft_listsize(b) > 0)
		pa(a, b);
}
