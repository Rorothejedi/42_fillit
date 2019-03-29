/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_area.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:03:59 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 10:53:53 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_area_define(int nb_line)
{
	int		i;
	int		y;
	int		size;
	int		nb_square;
	char	**area;

	i = -1;
	nb_square = ft_count_nb_piece(nb_line);
	size = ft_sqrt(nb_square * 4);
	if (!(area = malloc(sizeof(area) * size)))
		return (NULL);
	while (++i < size)
	{
		if (!(area[i] = malloc(sizeof(*area) * size + 1)))
			return (NULL);
		y = 0;
		while (y < size)
		{
			area[i][y] = '.';
			y++;
		}
		area[i][y] = '\0';
	}
	return (area);
}

char	**ft_area_increase(char **area)
{
	int		i;
	int		j;
	int		size;
	char	**new_area;

	i = -1;
	size = ft_count_size_area(area) + 1;
	if (!(new_area = malloc(sizeof(new_area) * size + 1)))
		return (NULL);
	while (++i < size)
	{
		if (!(new_area[i] = malloc(sizeof(*new_area) * size + 1)))
			return (NULL);
		j = -1;
		while (++j < size)
			new_area[i][j] = '.';
		new_area[i][j] = '\0';
	}
	return (new_area);
}

int		ft_area_display(char **area)
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
			ft_putchar(area[y][x]);
		ft_putchar('\n');
	}
	return (0);
}
