/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:03:40 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 16:33:11 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				ft_tetri_height(char **array, int y)
{
	int x;
	int temp;
	int height;
	int save_y;

	height = 0;
	save_y = (y == 0) ? y : y + 1;
	temp = -1;
	while (y < save_y + 4)
	{
		x = -1;
		while (array[y][++x])
		{
			if (array[y][x] == '#')
			{
				if (temp < y)
				{
					height++;
					temp = y;
				}
			}
		}
		y++;
	}
	return (height);
}

int				ft_tetri_width(char **array, int y)
{
	int width;

	width = ft_count_hash_left(array, y) + ft_count_hash_right(array, y) + 1;
	return (width);
}

t_tetriminos	*ft_stock_piece(char **array, int nb_line, int i)
{
	int				x;
	int				y;
	t_tetriminos	*list;
	t_tetriminos	*temp;

	y = -1;
	list = ft_new_tetriminos();
	temp = list;
	while (++y < nb_line && ++i < 5)
	{
		if (i == 4)
			temp = ft_add_tetriminos(list);
		if (y == 0 || i == 4)
		{
			temp->width = ft_tetri_width(array, y);
			temp->height = ft_tetri_height(array, y);
			if (i == 4)
				i = -1;
		}
		x = -1;
		while (array[y][++x])
			temp->piece[i][x] = array[y][x];
	}
	return (list);
}
