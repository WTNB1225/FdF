/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:40:30 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 21:17:22 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/*
#include <assert.h>
int main(void)
{
	t_list	*lst;
	char	*content = "hogehoge";
	lst = ft_lstnew((void *)42);
	assert(lst->content == (void *)42);
	assert(lst->next == NULL);
	lst = ft_lstnew(content);
	assert(lst->content == content);
	assert(lst->next == NULL);
}
*/
