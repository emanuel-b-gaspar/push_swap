/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:43:17 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/25 14:55:47 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ra(t_list **a)
{
	t_list	*second;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	(*a)->next = NULL;
	*a = second;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*second;
	t_list	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	second = (*b)->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = *b;
	(*b)->next = NULL;
	*b = second;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	second = (*a)->next;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = *a;
	(*a)->next = NULL;
	*a = second;
	second = (*b)->next;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = *b;
	(*b)->next = NULL;
	*b = second;
	write(1, "rr\n", 3);
}
