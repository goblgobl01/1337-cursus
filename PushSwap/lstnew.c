/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:38:52 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/04/04 16:54:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (NULL);
	stack_a->data = data;
	stack_a->next = NULL;
	stack_a->idx = 0;
	return (stack_a);
}
