/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:21:25 by wfung             #+#    #+#             */
/*   Updated: 2017/07/23 19:01:34 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static cmp_mid(t_env *e, char c, float coor)
{
	float	grid_mid_x;
	float	grid_y_mid;

	if (c == 'x')
	{
		grid_mid_x = (e->max_x - e->start_x) / 2;
	/*	if (grid_mid_x > e->win_mid_x)
			coor = coor + (grid_mid_x - e->win_mid_x);
		else
			coor = coor - (e->win_mid_x - grid_mid_x);
	*/	return (coor = coor + e->win_mid_x - grid_mid_x);
	}
	grid_y_mid = (e->max_y - e->start_y) / 2;
	/*	if (grid_y_mid > e->win_mid_y)
			coor = coor + (grid_y_mid - e->win_mid_y);
		else
			coor = coor - (e->win_mid_y - grid_y_mid);
	*/	return (coor = coor + e->win_mid_y - grid_y_mid);
}

void			translate(t_fdfstore *store, t_env *e)
{
	int		i;
	int		j;
	float	x_add;
	float	y_add;

	i = 0;
	x_add = cmp_mid(e, 'x', e->pts[0][0].x_stop);
	y_add = cmp_mid(e, 'y', e->pts[0][0].y_stop);
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
