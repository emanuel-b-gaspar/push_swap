/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebunga-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:49:19 by ebunga-g          #+#    #+#             */
/*   Updated: 2024/10/30 02:32:22 by ebunga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_atol(const char *str, t_list **a, char **matrix, int pos)
{
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if ((*str == '+' || *str == '-') && *(str + 1))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - 48;
		if (((result * sign) > INT_MAX || (result * sign) < INT_MIN))
		{
			free_matrix(matrix, pos);
			ft_exit_error(a);
		}
		str++;
	}
	return ((int)(result * sign));
}

void	ft_addlist(t_list **a, int value)
{
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		ft_exit_error(a);
	new->value = value;
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		last = *a;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	check_syntax(char *str, t_list **a, char **matrix, int pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			free_matrix(matrix, pos);
			ft_exit_error(a);
		}
		i++;
	}
}

void	ft_recept(t_list **a, char **av)
{
	char	**matrix;
	int		i;
	int		j;

	i = 1;
	while (av[i] != NULL)
	{
		matrix = ft_split(av[i], ' ');
		j = 0;
		while (matrix[j] != NULL)
		{
			check_syntax(matrix[j], a, matrix, j);
			ft_addlist(a, ft_atol(matrix[j], a, matrix, j));
			free(matrix[j]);
			j++;
		}
		free(matrix);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (check_empty_args(ac, av))
		return (write(2, "Error\n", 6), 1);
	ft_recept(&a, av);
	if (ft_duplicate(&a) == 1)
		ft_exit_error(&a);
	if (ft_desorganized(&a) == 1)
	{
		if (ft_listsize(&a) == 2)
			sa(&a);
		else if (ft_listsize(&a) < 6)
			ft_sort_small(&a, &b);
		else
			ft_merge_sort(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
