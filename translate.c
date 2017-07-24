/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:21:25 by wfung             #+#    #+#             */
/*   Updated: 2017/07/23 17:09:03 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	center_cmp(t_env *e, char c, float coor)
{
	float	grid_x_center;
	float	grid_y_center;

	if (c == 'x')
	{
		grid_x_center = (e->max_x - e->start_x) / 2;
	/*	if (grid_x_center > e->center_x)
			coor = coor + (grid_x_center - e->center_x);
		else
			coor = coor - (e->center_x - grid_x_center);
	*/	return (coor = coor + e->center_x - grid_x_center);
	}
	grid_y_center = (e->max_y - e->start_y) / 2;
	/*	if (grid_y_center > e->center_y)
			coor = coor + (grid_y_center - e->center_y);
		else
			coor = coor - (e->center_y - grid_y_center);
	*/	return (coor = coor + e->center_y - grid_y_center);
}

void			translate(t_fdfstore *store, t_env *e)
{
	int		i;
	int		j;
	float	x_add;
	float	y_add;

	i = 0;
	x_add = center_cmp(e, 'x', e->pts[0][0].x_stop);
	y_add = center_cmp(e, 'y', e->pts[0][0].y_stop);
	printf("xa %f ya %f\n", x_add, y_add);
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			e->pts[i][j].x_stop += x_add;
			e->pts[i][j].y_stop += y_add;
			j++;
		}
		i++;
	}
	x_add >= y_add ? (e->gap1 += x_add) : (e->gap1 += y_add);
	e->max_x += x_add;
	e->max_y += y_add;
	printf("g1 %f mx %f my %f\n", e->gap1, e->max_x, e->max_y);
}
