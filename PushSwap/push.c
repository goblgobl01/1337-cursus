#include "header.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (!stack1 || !(*stack1))
		return ;
	tmp = ft_lstnew((*stack1)->data);
	ft_lstadd_back(&stack2, tmp);
}