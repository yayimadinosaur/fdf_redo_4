/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:29:37 by wfung             #+#    #+#             */
/*   Updated: 2017/07/22 17:04:12 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdfstore	*store;
	t_env		*e;
	store = NULL;
	if (ac == 1)
		ft_putstr("Please include a .fdf file\n");
	if (ac == 2)
	{
		if (!(store = create_struct1()))//not sure if [if] is needed
			return (0);				//should display malloc fail msg?
		if (parse_fdf(av[1], av, store) == 1)
		{
			ft_putstr(".fdf parsing filename + file contents  pass!\n");
			if (save_values(av, store) != 1)
				ft_putstr("save_values malloc failed\n");
			print_array_int(store->array_int, store);	//testing array_int
			if (!(e = set_window1(600, store)))
				return (-1);	//notsure if proper return 
			e->mlx = mlx_init();
			e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "42");
			printf("win_x %i win_y %i cent_x %f cent_y %f start_x %i start_y %i end_x %f end_y %f h_gap %f w_gap %f gap1 %f\n", e->win_x, e->win_y, e->center_x, e->center_y, e->start_x, e->start_y, e->end_x, e->end_y, e->h_gap, e->w_gap, e->gap1);
			printf("mlx looping\n");
			//rotate(store, e);
			translate(store, e);
			draw2(e->mlx, e->win, e, store);
			mlx_loop(e->mlx);
		}
		else
		{
			free(store);
			ft_putstr(".fdf file invalid - fail main\n");
		}
	}
	return (0);
}

	/*	fdf flow?
	 *
	 * if (create_grid(av[1]) == 0)
				//free(grid?
			else
				if (store_pts(av[1]) == 0)
					//free stored_pts
				else
					draw_fdf();	//initialize mlx + loop

		rotate pts
		translation of pts
		free everything?
		exit key code
	*/
