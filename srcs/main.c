/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 12:23:55 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 10:55:06 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_create_array(int fd, int nb_line)
{
	int		x;
	int		y;
	char	*line;
	char	**arr;

	y = 0;
	line = NULL;
	if (!(arr = malloc(sizeof(arr) * nb_line)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		if (!(arr[y] = (char *)malloc(sizeof(*arr) * (ft_strlen(line) + 1))))
			return (NULL);
		while (line[++x])
			arr[y][x] = line[x];
		arr[y][x] = '\0';
		y++;
		free(line);
		line = NULL;
		if (!(line = malloc(0)))
			return (NULL);
	}
	return (arr);
}

int		ft_main_next(char **array, int nb_line)
{
	t_tetriminos	*list;
	char			**area;

	if (ft_check_square(array, nb_line) != 1
			|| ft_check_tetriminos(array, nb_line) != 1)
	{
		ft_putendl("error");
		return (0);
	}
	area = ft_area_define(nb_line);
	list = ft_stock_piece(array, nb_line, -1);
	ft_free(array, nb_line);
	area = ft_solver(list, area);
	ft_freelist(list);
	ft_area_display(area);
	ft_free(area, ft_count_size_area(area));
	return (0);
}

int		main(int argc, char **argv)
{
	int				fd;
	int				fd_bis;
	int				nb_line;
	char			**array;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		fd_bis = open(argv[1], O_RDONLY);
		nb_line = ft_count_nb_line(fd);
		array = ft_create_array(fd_bis, nb_line);
		ft_main_next(array, nb_line);
		close(fd);
		close(fd_bis);
	}
	else
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
