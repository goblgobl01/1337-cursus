/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:38:26 by mmaarafi          #+#    #+#             */
/*   Updated: 2024/11/08 13:38:39 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

// int main()
// {
// 	printf("im here on this function\n");
// 	// Create a hard-coded linked list:
//     // 1 -> 3 -> 1 -> 2 -> 1
// 	t_list* head = ft_lstnew("hello");
// 	t_list* new = ft_lstnew("my");
// 	t_list* another = ft_lstnew("name");
// 	ft_lstadd_front(&head, new);
// 	ft_lstadd_front(&new, another);
//     // Function call
//     printf("Count of nodes is %d", ft_lstsize(head));
//     return 0;
// }
