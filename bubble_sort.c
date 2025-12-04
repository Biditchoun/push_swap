/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:38:31 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 16:39:05 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sort(t_stack *a)
{
	int	i;
	int	j;
	int	buff;

	i = -1;
	while (++i < a->size)
	{
		j = i;
		while (++j < a->size)
		{
			if (a->stack[i] > a->stack[j])
			{
				buff = a->stack[i];
				a->stack[i] = a->stack[j];
				a->stack[j] = buff;
			}
		}
	}
	return (0);
}
