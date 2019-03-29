/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_piece.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 12:30:19 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 14:46:16 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_put_piece(t_tetriminos *list, char **area, int y, int x)
{
	int i;
	int j;
	int max_x;
	int max_y;

	j = ft_position_coord_list(list, 'y');
	max_x = x + list->width;
	max_y = y + list->height;
	while (y < max_y)
	{
		x = max_x - list->width;
		i = ft_position_coord_list(list, 'x') - ft_count_hash_left_list(list);
		while (x < max_x)
		{
			if (area[y][x] == '.' && list->piece[j][i] == '#')
				area[y][x] = list->letter;
			i++;
			x++;
		}
		j++;
		y++;
	}
	return (area);
}

int		ft_check_put_piece(t_tetriminos *list, char **area, int y, int x)
{
	int i;
	int j;
	int count;
	int max_x;
	int max_y;

	j = ft_position_coord_list(list, 'y');
	count = 0;
	max_x = x + list->width;
	max_y = y + list->height;
	while (y < max_y && y < ft_count_size_area(area))
	{
		x = max_x - list->width;
		i = ft_position_coord_list(list, 'x')
			- ft_count_hash_left_list(list) - 1;
		while (x < max_x && x < ft_count_size_area(area) && i++ > -42)
			if (area[y][x++] == '.' && list->piece[j][i] == '#')
				count++;
		j++;
		y++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int		ft_solve_piece(t_tetriminos *list, char **area, int y, int x)
{
	int size_area;
	int save_x;
	int tmp;

	tmp = 0;
	save_x = x;
	size_area = ft_count_size_area(area);
	while (y < size_area)
	{
		if (tmp == 0)
			x = save_x - 1;
		else
			x = -1;
		while (area[y][++x])
		{
			if (ft_check_put_piece(list, area, y, x) == 1)
			{
				ft_put_piece(list, area, y, x);
				return (1);
			}
			tmp = 1;
		}
		y++;
	}
	return (0);
}

char	**ft_delete_piece(t_tetriminos *list, char **area)
{
	int x;
	int y;
	int size_area;

	y = -1;
	size_area = ft_count_size_area(area);
	while (++y < size_area)
	{
		x = -1;
		while (area[y][++x])
		{
			if (area[y][x] == list->letter)
				area[y][x] = '.';
		}
	}
	return (area);
}
