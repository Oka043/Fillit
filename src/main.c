/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:01 by rhrab             #+#    #+#             */
/*   Updated: 2018/02/19 14:47:40 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		pre_valid(char *av)
{
	int		ret;
	int		fd;
	char	*buf;

	fd = open(av, O_RDONLY);
	buf = ft_strnew(546);
	ret = (read(fd, buf, 546)) % 21 - 20;
	close(fd);
	if (ret != 0)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_tetra	*tetra;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file_name\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	map = malloc(sizeof(t_map));
	tetra = malloc(sizeof(t_tetra));
	tetra->next = NULL;
	if (pre_valid(av[1]) || validator(fd, tetra))
	{
		ft_putstr("error\n");
		return (0);
	}
	print_map(solv(tetra, map));
	return (0);
}
