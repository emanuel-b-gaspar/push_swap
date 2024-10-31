/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isempty_and_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:58:32 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:26:07 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		str++;
	if (!str[i])
		return (1);
	return (0);
}

int	check_empty_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isempty(av[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_matrix(char **matrix, int pos)
{
	int	c;

	c = pos;
	while (matrix[c])
		free(matrix[c++]);
	free(matrix);
}
