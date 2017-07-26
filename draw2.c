/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:12:21 by wfung             #+#    #+#             */
/*   Updated: 2017/07/25 17:25:10 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_straight(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{

			j++;
		}
		i++;
	}
}
void		draw_right(void *mlx, void *win, t_env *e, t_fdfstore *store)	//right
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			gap = 0;
			while (gap <= e->gap1 && e->pts[i][j].x_stop + gap <= e->max_x)
			{
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop + gap,\
					   	e->pts[i][j].y_stop, 0xff00);	//green
				gap++;
			}
			printf("i %i j %i gap %f\n", i, j, gap);
			j++;
		}
		i++;
	}
	printf("x stop %f\n", e->pts[i -1][j - 1].x_stop);
}

void		draw_down(void *mlx, void *win, t_env *e, t_fdfstore *store)	//down
{
	int		i;
	int		j;
	float	gap;

	i = 0;
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			gap = 0;
			while (gap <= e->gap1 && e->pts[i][j].y_stop + gap <= e->max_y + 1)
			{
				mlx_pixel_put(mlx, win, e->pts[i][j].x_stop,\
						e->pts[i][j].y_stop + gap, 0xff0000);	//red
				gap++;
			}
	//		printf("i %i j %i gap %f\n", i, j, gap);
			j++;
		}
		i++;
	}
	printf("y stop %f\n", e->pts[i - 1][j - 1].y_stop);
}
void		draw2(void *mlx, void *win, t_env *e, t_fdfstore *store)
{
	printf("draw left chk %f\n", e->max_y);
	printf("draw right chk %f\n", e->max_x);
	draw_right(mlx, win, e, store);	//straight line
	draw_down(mlx, win, e, store);	//straight line

//	draw_gradual(mlx, win, e, store);	//gradual line
//	draw_sharp(mlx, win, e, store);	//sharp line
//	draw_straight(mlx, wine, e, store);	//new straight draw function
}

