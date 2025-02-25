/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:18:34 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/25 15:25:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	argument_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i][j] == '+' || str[i][j] == '-') && str[i][j + 1] != 0)
			j++;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		strs[i] = NULL;
		i++;
	}
	free (strs);
	strs = NULL;
}

void	add_arguments(t_stack **stack_a, char **strs)
{
	long long	var;
	t_stack		*tmp;
	int			i;

	i = 0;
	while (strs[i])
	{
		var = ft_atoi(strs[i]);
		if (var > INT_MAX || var < INT_MIN)
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			exit(0);
		}
		tmp = ft_lstnew(var);
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	free_strs(strs);
}

void	check_duplicate(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*another_tmp;
	int		count;

	tmp = *stack_a;
	while (tmp)
	{
		count = 0;
		another_tmp = *stack_a;
		while (another_tmp)
		{
			if (tmp->data == another_tmp->data)
				count++;
			another_tmp = another_tmp->next;
		}
		if (count > 1)
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			exit(0);
		}
		tmp = tmp->next;
	}
}

int is_sorted(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > (tmp->next)->data)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}

int	positioning(t_stack *tmp, int i)
{
	int	pos;

	pos = 0;
	while(tmp)
	{
		if(tmp->idx == 0 + i)
			break ;
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	smallest_element(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;
	int		length;
	int		i;

	length = ft_lstsize(*stack_a);
	if (length == 4)
		i = 1;
	else
		i = 0;
	while (i < 2)
	{
		if (length == 4)
			pos = positioning(*stack_a, 0);
		else
			pos = positioning(*stack_a, i);
		if (pos == 0)
			pb(stack_a, stack_b);
		else if (pos == 1)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
		}
		else if(pos == 2)
		{
			ra(stack_a);
			sa(stack_a);
			pb(stack_a, stack_b);
		}
		else if(pos == 3)
		{
			if(i == 0)
				rra(stack_a);
			rra(stack_a);
			pb(stack_a, stack_b);
		}
		else if(pos == 4)
		{
			if (i == 0)
			{
				rra(stack_a);
				pb(stack_a, stack_b);
			}
		}
		i++;
	}
}

void	sorting_three_numbers(t_stack **stack_a)
{
	if ((*stack_a)->data > ((*stack_a)->next)->data)
		sa(stack_a);
	if (!(is_sorted(stack_a)))
		rra(stack_a);
	if ((*stack_a)->data > ((*stack_a)->next)->data)
		sa(stack_a);
}

void	algorithms(t_stack **stack_a, t_stack **stack_b)
{
	int		length;

	indexing(stack_a);
	length = ft_lstsize((*stack_a));
	if (length == 1)
		return ;
	else if (length == 2)
	{
		if((*stack_a)->data > ((*stack_a)->next)->data)
			sa(stack_a);
	}
	else if (length == 3)
		sorting_three_numbers(stack_a);
	else if (length == 5 || length == 4)
	{
		smallest_element(stack_a, stack_b);
		sorting_three_numbers(stack_a);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
	else
	{
		pushing_b(stack_a, stack_b);
		pushing_a(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	char		**strs;
	int			i;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		if (strs && argument_check(strs))
			add_arguments(&stack_a, strs);
		else
		{
			write(2, "Error\n", 6);
			ft_lstclear(&stack_a);
			exit(0) ;
		}
		i++;
	}
	check_duplicate(&stack_a); 
	algorithms(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}

