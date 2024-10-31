/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:24:51 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:11:06 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_pilesize(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_piles_on_stack(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_merge_on_a(t_list **a, t_list **b, int pilesize_a, int pilesize_b)
{
	while (pilesize_a > 0 || pilesize_b > 0)
	{
		if ((pilesize_a > 0 && pilesize_b > 0) && (*b)->value < (*a)->value)
		{
			pa(a, b);
			pilesize_b--;
			pilesize_a++;
		}
		else if (pilesize_b > 0 && pilesize_a <= 0)
		{
			pa(a, b);
			pilesize_b--;
			pilesize_a++;
		}
		else
		{
			ra(a);
			pilesize_a--;
		}
	}
}

void	ft_merge_on_b(t_list **a, t_list **b, int pilesize_a, int pilesize_b)
{
	while (pilesize_a > 0 || pilesize_b > 0)
	{
		if ((pilesize_a > 0 && pilesize_b > 0) && (*a)->value < (*b)->value)
		{
			pb(a, b);
			pilesize_a--;
			pilesize_b++;
		}
		else if (pilesize_a > 0 && pilesize_b <= 0)
		{
			pb(a, b);
			pilesize_a--;
			pilesize_b++;
		}
		else
		{
			rb(b);
			pilesize_b--;
		}
	}
}

void	ft_merge_sort(t_list **a, t_list **b)
{
	int	i;
	int	halfsize;

	i = 0;
	halfsize = ft_listsize(a) / 2;
	while (i < halfsize)
	{
		pb(a, b);
		i++;
	}
	while (ft_listsize(b) > 0)
	{
		if (ft_piles_on_stack(b) >= ft_piles_on_stack(a))
			ft_merge_on_a(a, b, ft_pilesize(a), ft_pilesize(b));
		else
			ft_merge_on_b(a, b, ft_pilesize(a), ft_pilesize(b));
	}
}
