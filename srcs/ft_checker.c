/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checker.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 12:38:44 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 20:43:04 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_square(char **array, int nb_line)
{
	int		y;
	int		square;
	char	*line;

	y = -1;
	square = -1;
	line = NULL;
	if (nb_line > 130 || nb_line == 0)
		return (0);
	while (++y < nb_line && ++square < 5)
	{
		if (square < 4)
		{
			if (ft_check_square_line(array[y]) == 0)
				return (0);
		}
		else
		{
			if (array[y][0] != '\0')
				return (0);
			square = -1;
		}
	}
	return (1);
}

int		ft_check_square_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (i >= 4 || (line[i] != '.' && line[i] != '#'))
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int		ft_check_tetriminos(char **array, int nb_line)
{
	int		y;
	int		side;

	y = -1;
	side = 0;
	if (array[nb_line - 1][0] == '\0')
		return (0);
	while (++y < nb_line)
	{
		if ((side = ft_check_grid(side, nb_line, y, array)) == -1)
			return (0);
	}
	return (1);
}

int		ft_check_grid(int side, int nb_line, int y, char **array)
{
	int x;
	int tmp;

	x = -1;
	while (array[y][++x])
	{
		if (array[y][x] == '#' && x < 3 && y + 1 < nb_line
				&& array[y][x + 1] == '#' && array[y + 1][x] == '#'
				&& array[y + 1][x + 1] == '#')
			tmp = 1;
		if (array[y][x] == '#' && y + 1 < nb_line && array[y + 1][0] != '\0'
				&& array[y + 1][x] == '#')
			side++;
		side = ft_check_side(side, x, y, array);
	}
	if (array[y][0] == '\0' || y + 1 == nb_line)
	{
		if (side == 8 && tmp == 1)
			side = 6;
		if (side != 6)
			return (-1);
		side = 0;
		tmp = 0;
	}
	return (side);
}

int		ft_check_side(int side, int x, int y, char **array)
{
	if (array[y][x] == '#' && x > 0 && array[y][x - 1] == '#')
		side++;
	if (array[y][x] == '#' && y > 0 && array[y - 1][0] != '\0'
			&& array[y - 1][x] == '#')
		side++;
	if (array[y][x] == '#' && x < 3 && array[y][x + 1] == '#')
		side++;
	return (side);
}
