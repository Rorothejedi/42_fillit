/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:04:43 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 19:59:48 by antdelri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_free(char **array, int nb_line)
{
	int y;

	y = 0;
	while (y < nb_line)
	{
		free(array[y]);
		y++;
	}
	free(array);
	array = NULL;
}

void			ft_freelist(t_tetriminos *list)
{
	if (list->next)
		ft_freelist(list->next);
	ft_free(list->piece, 4);
	free(list);
}

t_tetriminos	*ft_new_tetriminos(void)
{
	int				i;
	t_tetriminos	*temp;

	i = -1;
	temp = NULL;
	if (!(temp = malloc(sizeof(t_tetriminos))))
		return (0);
	temp->piece = NULL;
	if (!(temp->piece = malloc(sizeof(char *) * 4)))
		return (0);
	while (++i < 4)
		temp->piece[i] = ft_strnew(4);
	temp->letter = 'A';
	temp->width = 0;
	temp->height = 0;
	temp->next = NULL;
	return (temp);
}

t_tetriminos	*ft_add_tetriminos(t_tetriminos *list)
{
	t_tetriminos *temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_new_tetriminos();
	temp->next->letter = temp->letter + 1;
	return (temp->next);
}
