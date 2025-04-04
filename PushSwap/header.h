/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:37:28 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/04/04 18:09:03 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				idx;
	struct s_stack	*next;
}t_stack;

char			**ft_split(char const *s, char c);
void			ft_lstclear(t_stack **stack_a);
void			ft_lstadd_back(t_stack **stack_a, t_stack *new);
long long		ft_atoi(const char *str);
t_stack			*ft_lstnew(int data);
void			pb(t_stack **stack1, t_stack **stack2);
void			pa(t_stack **stack1, t_stack **stack2);
void			ra(t_stack **stack);
void			rb(t_stack **stack);
void			rra(t_stack **stack);
void			rrb(t_stack **stack);
void			rrr(t_stack **stacka, t_stack **stackb);
void			rr(t_stack **stacka, t_stack **stackb);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
void			indexing(t_stack **stack_a);
void			pushing_b(t_stack **stack_a, t_stack **stack_b);
void			pushing_a(t_stack **stack_a, t_stack **stack_b);
int				ft_lstsize(t_stack *lst);
void			sa(t_stack **stack);
void			sb(t_stack **stack);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			algorithms(t_stack **stack_a, t_stack **stack_b);
void			handle_position(int pos, int i, 
					t_stack **stack_a, t_stack **stack_b);

#endif