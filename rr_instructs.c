/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:58:39 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 14:08:48 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *a, int fd)
{
	int	i;
	int	buff;

	if (a->size < 2)
		return (0);
	buff = a->stack[a->size - 1];
	i = a->size;
	while (--i)
		a->stack[i] = a->stack[i - 1];
	a->stack[0] = buff;
	write(fd, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *b, int fd)
{
	if (b->size < 2)
		return (0);
	rra(b, 10);
	write(fd, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int fd)
{
	rra(a, 10);
	rra(b, 10);
	write(fd, "rrr\n", 4);
	return (1);
}
