#include "header.h"

/**
 * swap_a: this function swap between the two first element on stacka
*/

void	swap_a(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = ft_lstnew((*stack_a)->data);
	(*stack_a)->data = ((*stack_a)->next)->data;
	((*stack_a)->next)->data = tmp->data;
	ft_lstclear(&tmp);
}