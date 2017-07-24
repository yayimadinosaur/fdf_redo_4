#include "fdf.h"
void	print_array_int(int **array_int, t_fdfstore *store)
{
	int		i;
	int		j;

	i = 0;
	printf("start print int_array\n");
	while (i < store->row)
	{
		j = 0;
		while (j < store->col)
		{
			printf("%i ", array_int[i][j]);
			j++;
		}
		printf("\nrow %i\n", i);
		i++;
	}
	printf("end print int_array\n");
}
