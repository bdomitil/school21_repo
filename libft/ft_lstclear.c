
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *temp;

    if (!lst[0])
        return ;
    temp = lst[0];
    
    while (lst[0]->next != NULL)
    {   
        temp = lst[0]->next;
        del(lst[0]->next);
        del(lst[0]->content);
        lst[0]= temp;
    }
    return ;
}
