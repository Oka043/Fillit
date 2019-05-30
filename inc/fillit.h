/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:19:25 by olaktion          #+#    #+#             */
/*   Updated: 2018/02/19 17:58:26 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_tetra
{
	struct s_tetra	*next;
	char			**tetramin;
	char			ch;
	int				x;
	int				y;
}				t_tetra;

typedef struct	s_offset
{
	int		x;
	int		y;
}				t_offset;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_map
{
	int		size;
	char	**map;
}				t_map;

size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_memdel(void **ap);

int				check_square_help(t_tetra *orgn, int j);
int				pre_valid(char *av);
int				check_square(t_tetra *tetra);
int				square_solv(t_map *map, t_tetra *tetra, int x, int y);
int				width(char *buf);
int				height_help(char *buf, int i);
int				height(char *buf);
t_pos			*get_pos(char *buf);
void			fill_tetra(char *buf, t_tetra *tetra, t_pos *pos, int i);
void			make_tetra(char *buf, t_tetra *tetra, char ch);
int				check_hits(char *buf);
int				check_symbols(char *buf, int ret);
int				validator(int fd, t_tetra *tetra);

void			store_tetra(t_map *map, t_tetra *tetra,
							t_offset *offset, char ch);
t_offset		*offset(int x, int y);
int				put_check(t_map *map, t_offset *offset, t_tetra *tetra);
int				map_solv(t_map *map, t_tetra *tetra);
int				size(t_tetra *tetra);
t_map			*solv(t_tetra *tetra, t_map *map);
void			print_map(t_map *map);

t_map			*map_alloc(t_map *map);
void			add_tetra_to_list(t_tetra *tetramin);
#endif
