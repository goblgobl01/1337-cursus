/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:53:03 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/25 09:48:08 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rra(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	ptr = *stack;
	tmp = NULL;
	while (ptr)
	{
		if ((ptr->next)->next == NULL)
		{
			tmp = ptr->next;
			ptr->next = NULL;
			break ;
		}
		ptr = ptr->next;
	}
	if (tmp)
		ft_lstadd_front(stack, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	ptr = *stack;
	tmp = NULL;
	while (ptr)
	{
		if ((ptr->next)->next == NULL)
		{
			tmp = ptr->next;
			ptr->next = NULL;
			break ;
		}
		ptr = ptr->next;
	}
	if (tmp)
		ft_lstadd_front(stack, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka);
	rrb(stackb);
	write(1, "rrr\n", 4);
}
