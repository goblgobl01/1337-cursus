/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:06:43 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/02 19:38:31 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_lstadd_back(t_stacka **lst, t_stacka *new)
{
	t_stacka	*ptr;
	t_stacka	*another_ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr != NULL)
	{
		another_ptr = ptr;
		ptr = ptr->next;
	}
	another_ptr->next = new;
}
