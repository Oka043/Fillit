/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:31:29 by olaktion          #+#    #+#             */
/*   Updated: 2018/02/19 17:55:07 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	make_tetra(char *buf, t_tetra *tetra, char ch)
{
	int		i;
	t_pos	*pos;

	i = 0;
	tetra->x = width(buf);
	tetra->y = height(buf);
	tetra->ch = ch;
	pos = get_pos(buf);
	fill_tetra(buf, tetra, pos, i);
}

int		check_hits(char *buf)
{
	int		i;
	int		hits;

	i = 0;
	hits = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) <= 20 && buf[i + 1] == '#')
				hits++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				hits++;
			if ((i + 5) <= 20 && buf[i + 5] == '#')
				hits++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				hits++;
		}
		i++;
	}
	if (hits == 6 || hits == 8)
		return (0);
	else
		return (1);
}

int		check_symbols(char *buf, int ret)
{
	int		i;
	int		hash;
	int		n;
	int		dot;

	i = 0;
	n = 0;
	hash = 0;
	dot = 0;
	while (i < ret)
	{
		if (buf[i] == '#')
			hash++;
		if (buf[i] == '\n')
			n++;
		if (buf[i] == '.')
			dot++;
		if (!(buf[i] == '#' || buf[i] == '.' || buf[i] == '\n'))
			return (1);
		i++;
	}
	if (dot != 12 || hash != 4 || n > 5 || n < 4)
		return (1);
	return (0);
}

int		validator(int fd, t_tetra *tetra)
{
	int		count;
	int		ret;
	char	ch;
	char	*buf;

	ch = 65;
	buf = ft_strnew(21);
	count = 1;
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		if (count++ > 26)
			return (1);
		if (check_symbols(buf, ret))
			return (1);
		if (check_hits(buf))
			return (1);
		make_tetra(buf, tetra, ch++);
		if (ret == 21)
			add_tetra_to_list(tetra);
		ft_memdel((void **)&buf);
		buf = ft_strnew(21);
		tetra = tetra->next;
	}
	return (0);
}
