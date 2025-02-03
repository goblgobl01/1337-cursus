/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:18:34 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:53 by mmaarafi         ###   ########.fr       */
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
	long long var;
	t_list *tmp;

	while(*strs)
	{
		var = ft_atoi(*strs);
		if(var > INT_MAX || var < INT_MIN)
		{
			write(2, "Error\n", 6);
			ft_lstclear(head);
			exit(0);
		}
		tmp = ft_lstnew(var);
		ft_lstadd_back(head, tmp);
		strs++;
	}
}

void check_duplicate(t_list **head)
{
	t_list *tmp;
	t_list *another_tmp;
	int count;
	
	tmp = *head;
	while(tmp)
	{
		count = 0;
		another_tmp = *head;
		while(another_tmp)
		{
			if(tmp->data == another_tmp->data)
				count++;
			another_tmp = another_tmp->next;  
		}
		if(count > 1)
		{
			write(2, "Error\n", 6);
			ft_lstclear(head);
			exit(0);
		}
		tmp = tmp->next;
	}
}

int main(int ac, char **av)
{
	char	**strs;
	int		i;
	t_list	*head;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		if(argument_check(strs))
			add_arguments(&head, strs);
		else
		{
			write(2, "Error\n", 6);
			ft_lstclear(&head);
			break;
		}
		i++;
	}
	check_duplicate(&head);
	return (0);
}
