/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:18:34 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/02 21:14:10 by mmaarafi         ###   ########.fr       */
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

t_list *add_arguments(char **strs)
{
	int var;
	t_list *head;
	t_list *tmp;

	while(*strs)
	{
		var = ft_itoa(strs);
		tmp->data = var;
		tmp->next = NULL;
		ft_lstadd_back(&head, tmp);
		strs++;
	}

	return (head);
}

int main(int ac, char **av)
{
	char	**strs;
	int		i;
	t_list	*head;

	i = 2;
	while (i < ac)
	{
		strs = ft_split(av[i], " ");
		if(argument_check(strs))
			head = add_arguments(strs);
		else
		{
			ft_lstclear(&head);
			break;
		}
		i++;
	}
}
