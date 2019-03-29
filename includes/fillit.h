/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 13:06:24 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 19:35:23 by antdelri    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_tetriminos
{
	char				**piece;
	char				letter;
	int					width;
	int					height;
	struct s_tetriminos	*next;
}				t_tetriminos;

char			**ft_create_array(int fd, int nb_line);

void			ft_free(char **array, int nb_line);
void			ft_freelist(t_tetriminos *list);

int				ft_count_nb_line(int fd);
int				ft_count_nb_piece(int nb_line);
int				ft_count_size_area(char **area);
int				ft_count_hash_left_list(t_tetriminos *list);
int				ft_count_hash_right_list(t_tetriminos *list);
int				ft_count_hash_left(char **array, int y);
int				ft_count_hash_right(char **array, int y);

int				ft_check_square(char **array, int nb_line);
int				ft_check_square_line(char *line);
int				ft_check_tetriminos(char **array, int nb_line);
int				ft_check_grid(int side, int nb_line, int y, char **array);
int				ft_check_side(int side, int x, int y, char **array);

char			**ft_area_define(int nb_line);
char			**ft_area_increase(char **area);
int				ft_area_display(char **area);

t_tetriminos	*ft_new_tetriminos(void);
t_tetriminos	*ft_add_tetriminos(t_tetriminos *list);

int				ft_tetri_height(char **array, int y);
int				ft_tetri_width(char **array, int y);
t_tetriminos	*ft_stock_piece(char **array, int nb_line, int i);

int				ft_position_coord_list(t_tetriminos *list, char coord);
int				ft_position_coord(char **array, int y, char coord);
int				ft_position_letter(char **area, char letter);

char			**ft_put_piece(t_tetriminos *list, char **area, int y, int x);
int				ft_check_put_piece(t_tetriminos *l, char **area, int y, int x);
int				ft_solve_piece(t_tetriminos *list, char **area, int y, int x);
char			**ft_delete_piece(t_tetriminos *list, char **area);

char			**ft_solver(t_tetriminos *list, char **area);

#endif
