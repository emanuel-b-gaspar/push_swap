/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:34 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:34:40 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_listsize(t_list **list)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = *list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_desorganized(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_duplicate(t_list **a)
{
	t_list	*current;
	t_list	*compare;

	current = *a;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_free_stack(t_list **a)
{
	t_list	*tmp;

	while (*a != NULL)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	ft_exit_error(t_list **a)
{
	ft_free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
