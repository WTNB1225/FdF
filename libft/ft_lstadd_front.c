/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:34:38 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 21:45:53 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <assert.h>
int main(void)
{
	t_list *l;

	char *content = "hoge";
	l = ft_lstnew(content);
	ft_lstadd_front(&l, ft_lstnew((void *)42));
	assert(l->content == (void *)42);
	assert((l->next)->next == NULL);
	assert((l->next)->content == content);
}
*/
