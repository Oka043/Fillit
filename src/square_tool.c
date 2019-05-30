/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:56:49 by rhrab             #+#    #+#             */
/*   Updated: 2018/02/19 17:59:55 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		check_square_help(t_tetra *orgn, int j)
{
	int		i;

	while (j < orgn->y)
	{
		if (orgn->x == orgn->next->x)
		{
			i = 0;
			while (i < orgn->x)
			{
				if (orgn->tetramin[j][i] == orgn->next->tetramin[j][i])
					i++;
				else
					return (1);
			}
		}
		else
			return (1);
		j++;
	}
	return (0);
}

int		check_square(t_tetra *tetra)
{
	int		j;
	t_tetra *orgn;

	orgn = tetra;
	while (orgn->next != NULL)
	{
		if (orgn->y == orgn->next->y)
		{
			j = 0;
			if (check_square_help(tetra, j))
				return (1);
		}
		else
			return (1);
		orgn = orgn->next;
	}
	return (0);
}
