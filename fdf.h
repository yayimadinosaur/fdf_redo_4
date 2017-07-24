/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/07/23 19:02:30 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <unistd.h> 
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "minilibx_macos/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define WHT 0xfffafa
#define	RED 0xff0000
#define GRN 0xff00


#include <stdio.h>	//

typedef	struct			s_fdfstore
{
	int					**array_int;	//add pts struct?
	int					row;
	int					col;
}						t_fdfstore;

//values for the 3 pts; not sure if needed?
typedef struct			s_pts
{
	float					x;
	float					y;
	float					z;
	float					x_stop;
	float					y_stop;
}						t_pts;	//malloc for (**t_pts) row * col

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					win_size_x;	//win
	int					win_size_y;	//win
	float				win_mid_x;	//win
	float				win_mid_y;	//win
	int					start_x;	//grid
	int					start_y;	//grid
	float				end_x;		//
	float				end_y;
	float				h_gap;
	float				w_gap;
	float				gap1;
	float				max_x;
	float				max_y;
	t_pts				**pts;
}						t_env;

int			parse_fdf(char *str, char **av, t_fdfstore *store);

t_fdfstore	*create_struct1(void);
int			save_values(char **av, t_fdfstore *store);
void		array_int(char **result_str, int n, int *array);

t_env		*set_window1(int n, t_fdfstore *store);
void		draw2(void *mlx, void *win, t_env *e, t_fdfstore *store);

void		rotate(t_fdfstore *store, t_env *e);
void		translate(t_fdfstore *store, t_env *e);
//ttest functions
void		print_array_int(int **array_int, t_fdfstore *store);

#endif
