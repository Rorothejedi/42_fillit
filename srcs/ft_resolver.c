/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resolver.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 11:52:43 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 19:05:54 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_solver_next(t_tetriminos *list, char **area, int y, int x)
{
	if (ft_solve_piece(list, area, y, x))
	{
		if (ft_solver(list->next, area) == NULL)
		{
			area = ft_delete_piece(list, area);
			return (0);
		}
		return (1);
	}
	return (0);
}

char	**ft_solver(t_tetriminos *list, char **area)
{
	int				x;
	int				y;
	int				size_area;

	x = -1;
	y = 0;
	size_area = ft_count_size_area(area);
	if (list != NULL)
		while (ft_solver_next(list, area, y, x++) == 0 && y < size_area)
		{
			if (x == size_area - 1 && y == size_area - 1)
			{
				area = ft_area_increase(area);
				if (list->letter == 'A')
					return (ft_solver(list, area));
				return (NULL);
			}
			else if (x == size_area - 1)
			{
				x = 0;
				y++;
			}
		}
	return (area);
}
