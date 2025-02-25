/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:50:44 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/25 12:16:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pa(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (!stack1 || !(*stack1))
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack2, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (!stack1 || !(*stack1))
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack2, tmp);
	write(1, "pb\n", 3);
}
