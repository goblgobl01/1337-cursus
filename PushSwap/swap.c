/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:54:17 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/24 21:28:32 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	tmp = ft_lstnew((*stack)->data);
	(*stack)->data = ((*stack)->next)->data;
	((*stack)->next)->data = tmp->data;
	ft_lstclear(&tmp);
	write(1, "sa\n", 3);
}
void	sb(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	tmp = ft_lstnew((*stack)->data);
	(*stack)->data = ((*stack)->next)->data;
	((*stack)->next)->data = tmp->data;
	ft_lstclear(&tmp);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
