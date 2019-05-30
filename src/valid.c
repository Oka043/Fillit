/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:40 by rhrab             #+#    #+#             */
/*   Updated: 2018/02/19 14:57:28 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		width(char *buf)
{
	int		i;
	int		start;
	int		end;

	i = 1;
	start = 4;
	end = 0;
	while (buf[i - 1])
	{
		if (buf[i - 1] == '#' && i % 5 < start)
			start = i % 5;
		if (buf[i - 1] == '#' && i % 5 > end)
			end = i % 5;
		i++;
	}
	i = 0;
	while (start <= end)
	{
		start++;
		i++;
	}
	return (i);
}

int		height_help(char *buf, int i)
{
	int		temp;
	int		k;

	temp = 0;
	k = i;
	while ((k + 5) <= 20 && buf[k] == '#' && buf[k + 5] == '#')
	{
		if ((k + 10) <= 20 && buf[k] == '#' && buf[k + 9] == '#' &&
				buf[k + 10] != '#')
			temp++;
		if ((k + 11) <= 20 && buf[k] == '#' && buf[k + 11] == '#' &&
				buf[k + 10] != '#')
			temp++;
		temp++;
		k += 5;
	}
	return (temp);
}

int		height(char *buf)
{
	int		i;
	int		temp;
	int		height;

	i = 0;
	height = 0;
	while (buf[i])
	{
		temp = height_help(buf, i);
		if (temp > height)
			height = temp;
		i++;
	}
	return (height + 1);
}

t_pos	*get_pos(char *buf)
{
	int		i;
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	pos->x = 4;
	pos->y = 0;
	i = 1;
	while (buf[i - 1] != '#')
		i++;
	pos->y = i / 5;
	i = 1;
	while (buf[i - 1])
	{
		if (buf[i - 1] == '#' && (i % 5) < pos->x)
			pos->x = (i % 5);
		i++;
	}
	pos->x -= 1;
	return (pos);
}

void	fill_tetra(char *buf, t_tetra *tetra, t_pos *pos, int i)
{
	int		j;
	int		k;

	j = 0;
	tetra->tetramin = (char **)malloc(sizeof(char *) * tetra->y + 1);
	while (buf[i])
	{
		k = 0;
		if (j > tetra->y || (j == 1 && tetra->y == 1))
			break ;
		tetra->tetramin[j] = malloc(sizeof(char) * tetra->x + 1);
		while (pos->y > 0)
		{
			i += 5;
			pos->y -= 1;
		}
		while (k < tetra->x)
			tetra->tetramin[j][k++] = buf[(i++) + pos->x];
		tetra->tetramin[j][k] = '\0';
		while (buf[i] != '\n' && i < 21)
			i++;
		j++;
		i++;
	}
}
