/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:46:05 by wfung             #+#    #+#             */
/*   Updated: 2017/07/22 16:05:40 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//checks to see if all the characters inside .fdf are valid
//	i.e. 0 - 9, '-', 0x for hex, and spaces
//		spacing depends on the numbers?

static int		parse_contents(char **av)
{
	int		i;
	int		fd;
	char	*line;

	int		chk_line = 0;	//

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-'
					&& line[i + 1] >= '0' && line[i + 1] <= '9')
				|| line[i] == ' ')
				i++;
			else
			{
				printf("parse_contents line #%i char#%i fails\n", chk_line, i);	//
				free(line);
				close(fd);
				return (0);
			}
		}
		free(line);
		chk_line++;	//
	}
	close(fd);
	return (1);
}

//maybe add to libft?
static int		count_num_str(char *str, int n, char stop)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != stop)
	{
		if (str[i] >= '0' && str[i] <= '9' &&
				(str[i + 1] == ' ' || str[i + 1] == n
				 || str[i + 1] == stop))
		{
//			printf("str[i] count = %c %i\n", str[i], i);
			count++;
		}
//		printf("[%c]", str[i]);
		i++;
	}
//	printf("count == %i\n", count);
	return (count);
}

/*	not sure if needed if count_num_str is used instead
 *	maybe add to libft?
static int		count_chr_str(char *str, int n, char stop)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != stop)
	{
		if (str[i] == (char)n && str[i + 1] != (char)n)
			count++;
		i++;
	}
	return (count);
}
*/

static int		parse_file(char **av, t_fdfstore *store)
{
	int			fd;
	char		*buff;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &buff) == 1)
	{
		store->col = count_num_str(buff, '\n', '\0');
		if (store->col != count_num_str(buff, '\n', '\0'))
		{
			close(fd);
			free(buff);
			ft_putstr("Invalid file contents\n");
			return (0);
		}
		free(buff);
		store->row = store->row + 1;
	}
	if (store->row < 2 || store->col < 2)
	{
		ft_putstr("Invalid file contents\n");
		return (0);
	}
	printf("parse row = %i\n", store->row);	//
	printf("parse col = %i\n", store->col);	//
	close(fd);
	return (1);
}

static int		parse_filename(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if (i < 4)
	{
		printf("file name too short\n");//
		return (0);
	}
	if (str[i] != 'f' && str[i - 1] != 'd' && str[i - 2] != 'f'
			&& str[i - 3] != '.')
	{
		printf("file extension not correct\n");
		return (0);
	}
	return (1);
}

int		parse_fdf(char *str, char **av, t_fdfstore *store)
{
	if (parse_filename(str) != 1)
	{
		ft_putstr(".fdf filename invalid\n");
		return (0);
	}
	if (parse_contents(av) == 0)
	{
		ft_putstr(".fdf contents invalid\n");
		return (0);
	}
	if (parse_file(av, store) != 1)
	{
		ft_putstr(".fdf file contents invalid\n");
		return (0);
	}
	return (1);
}
