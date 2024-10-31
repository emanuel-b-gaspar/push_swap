/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:17:31 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/25 14:41:08 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sa(t_list **a)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	t_list	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "ss\n", 3);
}
