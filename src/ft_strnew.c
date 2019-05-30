/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:00:25 by rhrab             #+#    #+#             */
/*   Updated: 2018/02/13 18:02:23 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (NULL);
	while (i <= size)
	{
		arr[i] = '\0';
		i++;
	}
	return (arr);
}
