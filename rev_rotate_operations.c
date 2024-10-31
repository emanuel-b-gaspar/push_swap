/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:09 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:33:39 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	rra(t_list **a)
{
	t_list	*before_last;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	before_last->next = NULL;
	*a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*before_last;
	t_list	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	before_last = (*b);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = *b;
	before_last->next = NULL;
	*b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*before_last;
	t_list	*last;

	if ((*a == NULL || (*a)->next == NULL)
		|| (*b == NULL || (*b)->next == NULL))
		return ;
	before_last = (*a);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	before_last->next = NULL;
	*a = last;
	before_last = (*b);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = *b;
	before_last->next = NULL;
	*b = last;
	write(1, "rrr\n", 4);
}
