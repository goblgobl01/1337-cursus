/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:33:13 by codespace         #+#    #+#             */
/*   Updated: 2025/04/04 18:07:48 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	indexing(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*another_tmp;

	tmp = *stack_a;
	another_tmp = *stack_a;
	while (tmp)
	{
		another_tmp = *stack_a;
		while (another_tmp)
		{
			if (another_tmp->data < tmp->data)
				(tmp->idx)++;
			another_tmp = another_tmp->next;
		}
		tmp = tmp->next;
	}
}

void	pushing_b(t_stack **stack_a, t_stack **stack_b)
{
	int		length_a;
	int		range;
	int		i;

	length_a = ft_lstsize(*stack_a);
	range = 0.048 * length_a + 10;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->idx >= i && (*stack_a)->idx <= (i + range))
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->idx < i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

int	position(t_stack **stack_b)
{
	t_stack	*tmpb;
	int		length;
	int		pos;

	length = ft_lstsize(*stack_b);
	pos = 0;
	tmpb = *stack_b;
	while (tmpb)
	{
		if (tmpb->idx == (length - 1))
			return (pos);
		tmpb = tmpb->next;
		pos++;
	}
	return (0);
}

void	pushing_a(t_stack **stack_a, t_stack **stack_b)
{
	int		length;
	int		pos;

	while (*stack_b)
	{
		length = ft_lstsize(*stack_b);
		pos = position(stack_b);
		if (pos == 0)
		{
			pa(stack_b, stack_a);
			continue ;
		}
		if (pos > (length / 2))
			rrb(stack_b);
		else
			rb(stack_b);
	}
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
