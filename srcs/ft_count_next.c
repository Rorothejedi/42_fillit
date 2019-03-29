/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_next.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:09:50 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 16:31:25 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_count_hash_left(char **array, int y)
{
	int count;
	int x;
	int temp;
	int save_y;

	count = 0;
	save_y = (y == 0) ? y : y + 1;
	y = (y == 0) ? y : y + 1;
	while (y < save_y + 4)
	{
		x = -1;
		temp = 0;
		while (++x < ft_position_coord(array, save_y, 'x'))
			if (array[y][x] == '#')
				temp++;
		if (count < temp)
			count = temp;
		y++;
	}
	return (count);
}

int		ft_count_hash_right(char **array, int y)
{
	int count;
	int x;
	int temp;
	int save_y;

	count = 0;
	save_y = (y == 0) ? y : y + 1;
	y = (y == 0) ? y : y + 1;
	while (y < save_y + 4)
	{
		x = 4;
		temp = 0;
		while (--x > ft_position_coord(array, save_y, 'x'))
			if (array[y][x] == '#')
				temp++;
		if (count < temp)
			count = temp;
		y++;
	}
	return (count);
}
