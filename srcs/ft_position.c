/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_position.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:03:30 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 16:33:46 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_position_coord_list(t_tetriminos *list, char coord)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (list->piece[y][x] == '#')
			{
				if (coord == 'x')
					return (x);
				else if (coord == 'y')
					return (y);
			}
	}
	return (0);
}

int		ft_position_coord(char **array, int y, char coord)
{
	int x;
	int save_y;

	save_y = y;
	while (y < save_y + 4)
	{
		x = -1;
		while (++x < 4)
			if (array[y][x] == '#')
			{
				if (coord == 'x')
					return (x);
				else if (coord == 'y')
					return (y);
			}
		y++;
	}
	return (0);
}

int		ft_position_letter(char **area, char letter)
{
	int x;
	int y;
	int size_area;
	int coord[2];

	y = -1;
	size_area = ft_count_size_area(area);
	while (++y < size_area)
	{
		x = -1;
		while (area[y][++x])
		{
			if (area[y][x] == letter)
			{
				coord[0] = y;
				coord[1] = x;
				return (*coord);
			}
		}
	}
	return (0);
}
