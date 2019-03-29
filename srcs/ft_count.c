/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:04:54 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 16:31:03 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_count_nb_line(int fd)
{
	int		nb_line;
	char	*line;

	nb_line = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		line = NULL;
		nb_line++;
	}
	return (nb_line);
}

int		ft_count_nb_piece(int nb_line)
{
	int i;
	int j;
	int nb_square;

	i = -1;
	j = 0;
	nb_square = 0;
	while (++i < nb_line)
	{
		if (j == 4)
		{
			nb_square++;
			j = 0;
		}
		else if (nb_line == 4)
			return (1);
		j++;
	}
	return (nb_square);
}

int		ft_count_size_area(char **area)
{
	int size;

	size = 0;
	while (area[0][size])
		size++;
	return (size);
}

int		ft_count_hash_left_list(t_tetriminos *list)
{
	int count;
	int y;
	int x;
	int temp;

	count = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		temp = 0;
		while (++x < ft_position_coord_list(list, 'x'))
			if (list->piece[y][x] == '#')
				temp++;
		if (count < temp)
			count = temp;
	}
	return (count);
}

int		ft_count_hash_right_list(t_tetriminos *list)
{
	int count;
	int y;
	int x;
	int temp;

	count = 0;
	y = -1;
	while (++y < 4)
	{
		x = 4;
		temp = 0;
		while (--x > ft_position_coord_list(list, 'x'))
			if (list->piece[y][x] == '#')
				temp++;
		if (count < temp)
			count = temp;
	}
	return (count);
}
