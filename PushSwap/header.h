/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:37:28 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/06 17:07:44 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stacka
{
	int				data;
	struct s_stacka	*next;
}t_stacka;

typedef struct s_stackb
{
	int				data;
	struct s_stackb	*next;
}t_stackb;

char			**ft_split(char const *s, char c);
void			ft_lstclear(t_stacka **lst);
void			ft_lstadd_back(t_stacka **lst, t_stacka *new);
long long		ft_atoi(const char *str);
t_stacka		*ft_lstnew(int data);

#endif