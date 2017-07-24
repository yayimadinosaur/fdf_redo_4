/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:44:06 by wfung             #+#    #+#             */
/*   Updated: 2017/07/24 13:16:01 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//removing the 10% and starting at 0,0
//ending at end - 20%
t_pts	**ft_setpts1(t_fdfstore *store, t_env *e)
{
	t_pts	**pts;
	int		i;
	int		j;

	i = 0;
	if (!(pts = (t_pts**)malloc(sizeof(t_pts*) * (store->row))))
		return (NULL);
	while (i < store->row)
	{
		j = 0;
			if (!(pts[i] = (t_pts*)malloc(sizeof(t_pts) * (store->col))))
				return (NULL);
		while (j < store->col)
		{
			pts[i][j].x = i;
			pts[i][j].y = j;
			pts[i][j].z = store->array_int[i][j];
			pts[i][j].x_stop = (e->gap1 * j);	//remember to flip x + y accordingly
			pts[i][j].y_stop = (e->gap1 * i);
			printf("[i=%i][j=%i]pts[x=%f][y=%f][z=%f][x_stop=%f][y_stop=%f]\n", i, j, pts[i][j].x, pts[i][j].y, pts[i][j].z, pts[i][j].x_stop, pts[i][j].y_stop);
			j++;
		}
		printf("\n");
		i++;
	}
	return (pts);
}

t_env	*set_window1(int n, t_fdfstore *store)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env) * (1))))
		return (NULL);
	if (n < 0)
		ft_putstr("window size needs to be positive\n");
	if (n == 0)
		ft_putstr("window size needs to be > 0\n");
	e->win_size_x = n;
	e->win_size_y = n;
	e->win_mid_x = n / 2;
	e->win_mid_y = n / 2;
	e->start_x = 0;
	e->start_y = 0;
	e->end_x = n - (2 * (n / 10));
	e->end_y = n - (2 * (n / 10));
	e->h_gap = (e->end_y - e->start_y) / (store->row - 1);
	e->w_gap = (e->end_x - e->start_x) / (store->col - 1);
	e->gap1 = (e->h_gap >= e->w_gap ? e->w_gap : e->h_gap);
	e->pts = ft_setpts1(store, e);
	e->max_x = e->start_x + e->gap1 * (store->col - 1);
	e->max_y = e->start_y + e->gap1 * (store->row - 1);
//	e->mlx = mlx_init();
//	e->win = mlx_new_window(e->mlx, e->win_size_x, e->win_size_y, "42");
	return (e);
}
