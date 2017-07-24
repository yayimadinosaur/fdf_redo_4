/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:07:22 by wfung             #+#    #+#             */
/*   Updated: 2017/07/05 13:08:40 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(*t_fdfstore store)
{
	free(store);
	return ;
}

//might need to add static functions to free the remaining parts
//	i.e. int array + whatever mallocs 
