/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:56:07 by pfalasch          #+#    #+#             */
/*   Updated: 2023/03/28 09:56:08 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Takes as a parameter an element and frees the memory of the element’s 
*	content using the function ’del’ given as a parameter and free the element.
*	The memory of ’next’ must not be freed.
*	PARAMETERS
*	#1. The element to free.
*	#2. The address of the function used to delete the content.
*	RETURN VALUES
*	-
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{	
		del(lst->content);
		free(lst);
	}
}
