#include "header.h"

void	rrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *ptr;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	ptr = *stack;
	while(ptr)
	{
		if((ptr->next)->next == NULL)
		{
			tmp = ptr->next;
			ptr->next = NULL;
			break;
		}
	}
	ft_lstadd_front(stack, tmp);
}