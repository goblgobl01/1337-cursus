# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <ctype.h>

typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}t_list;

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list    *ptr;

    if (!del || !lst)
        return ;
    if (!*lst)
        return ;
    while (*lst)
    {
        ptr = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = ptr;
    }
}

t_list    *ft_lstnew(void *content)
{
    t_list    *head;

    head = malloc(sizeof(t_list));
    if (head == NULL)
        return (NULL);
    head->content = content;
    head->next = NULL;
    return (head);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list    *ptr;
    t_list    *another_ptr;

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


t_list    *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    printf("i entered lst_map\n");
    void    *ptr;
    t_list    *new_lst;
    t_list    *new_node;
    t_list    *itirator;

    ptr = f(lst->content);
    new_lst = ft_lstnew(ptr);
    if (new_lst == NULL)
    {
        free (ptr);
        return (NULL);
    }
    printf("the new list have been created : %s\n", (new_lst->content));
    // return (NULL);
    itirator = lst->next;
    while (itirator)
    {
        // printf("im here\n");
        printf("this is lst->content : %s\n", (itirator->content));
        ptr = f(itirator->content);
        new_node = ft_lstnew(ptr);
        if (new_node == NULL)
        {
            free(ptr);
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_node);
        itirator = itirator->next;
    }
    return (new_lst);
}

void    *ft_map(void *ct)
{
    int i;
    void    *c;
    char    *pouet;

    c = ct;
    i = -1;
    pouet = (char *)c;
    while (pouet[++i])
        if (pouet[i] == 'o')
            pouet[i] = 'a';
    return (c);
}

void    ft_del(void *content)
{
    free(content);
}

t_list    *ft_lstnewone(void *content)
{
    t_list    *elem;

    elem = (t_list *)malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    if (!content)
        elem->content = NULL;
    else
        elem->content = content;
    elem->next = NULL;
    return (elem);
}

int main()
{
    t_list        *elem;
    t_list        *elem2;
    t_list        *elem3;
    t_list        *elem4;
    t_list        *list;
    t_list  *new_lst;
    char        *str = strdup("lorem");
    char        *str2 = strdup("ipsum");
    char        *str3 = strdup("dolor");
    char        *str4 = strdup("sit");

    elem = ft_lstnewone(str);
    elem2 = ft_lstnewone(str2);
    elem3 = ft_lstnewone(str3);
    elem4 = ft_lstnewone(str4);
    elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;  
    new_lst = ft_lstmap(elem, &ft_map, &ft_del);
    while (new_lst)
    {
        printf("this is new_lst->content : %s\n", (new_lst->content));
        new_lst = new_lst->next;
    }
}
