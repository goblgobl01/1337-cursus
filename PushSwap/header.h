/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:37:28 by mmaarafi          #+#    #+#             */
/*   Updated: 2025/02/03 18:34:22 by mmaarafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}t_list;

char			**ft_split(char const *s, char c);
void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
long long		ft_atoi(const char *str);
t_list			*ft_lstnew(int data);

#endif