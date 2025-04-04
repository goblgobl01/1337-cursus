/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:48:16 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/04/04 18:01:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > (tmp->next)->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	positioning(t_stack *tmp, int i)
{
	int	pos;

	pos = 0;
	while (tmp)
	{
		if (tmp->idx == 0 + i)
			break ;
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	handle_position(int pos, int i, t_stack **stack_a, t_stack **stack_b)
{
	if (pos == 1)
		sa(stack_a);
	else if (pos == 2)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (pos == 3)
	{
		if (i == 0)
			rra(stack_a);
		rra(stack_a);
	}
	else if (pos == 4)
	{
		if (i == 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	smallest_element(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;
	int	length;
	int	i;

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
		handle_position(pos, i, stack_a, stack_b);
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
	int	length;

	indexing(stack_a);
	length = ft_lstsize((*stack_a));
	if (length == 1)
		return ;
	else if (length == 2)
	{
		if ((*stack_a)->data > ((*stack_a)->next)->data)
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
