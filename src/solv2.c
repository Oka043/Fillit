/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:32:50 by olaktion          #+#    #+#             */
/*   Updated: 2018/02/19 17:33:50 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		size(t_tetra *tetra)
{
	int		i;
	int		size;
	t_tetra *origin;

	i = 0;
	size = 2;
	origin = tetra;
	while (origin != NULL)
	{
		origin = origin->next;
		i++;
	}
	while (size * size < i * 4)
		size++;
	if (!(check_square(tetra)) && size % 2 != 0)
		size++;
	return (size);
}

t_map	*solv(t_tetra *tetra, t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	map->size = size(tetra);
	map = map_alloc(map);
	if (!(check_square(tetra)))
		square_solv(map, tetra, x, y);
	else
		while (!map_solv(map, tetra))
		{
			map->size++;
			ft_memdel((void **)&(map)->map);
			map = map_alloc(map);
		}
	return (map);
}

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}
