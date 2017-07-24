/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:05:04 by wfung             #+#    #+#             */
/*   Updated: 2017/07/07 16:48:35 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdfstore	*create_struct1(void)
{
	t_fdfstore	*store;

	if (!(store = (t_fdfstore*)malloc(sizeof(t_fdfstore))))
		return (NULL);
	store->col = 0;
	store->row = 0;
	return (store);
}

//need to zero values inside struct??
