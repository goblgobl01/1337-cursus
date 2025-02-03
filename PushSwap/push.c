/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:18:34 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/03 15:50:03 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int argument_check(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if((str[i][j] == '+' || str[i][j] == '-') && str[i][j + 1] != 0)
			j++;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void add_arguments(t_list **head, char **strs)
{
	int var;
	int i;
	t_list *tmp;

	i = 0;
	while(strs[i])
	{
		var = ft_atoi(*strs);
		tmp = ft_lstnew(var);
		ft_lstadd_back(head, tmp);
		i++;
	}
}

int main()
{
	char	*av[] = {"1", "2", NULL};
	char	**strs;
	int		i;
	t_list	*head;

	head = NULL;
	i = 0;
	while (i < 3)
	{
		strs = ft_split(av[i], ' ');
		if(argument_check(strs))
			add_arguments(&head, strs);
		else
		{
			ft_lstclear(&head);
			break;
		}
		i++;
	}

	while(head)
	{
		printf("%d \n", head->data);
		head = head->next;
	}

	return (0);
}
