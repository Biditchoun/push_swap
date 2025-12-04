/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:58:39 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/03 20:16:09 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *a, int fd)
{
	int	i;
	int	buff;

	if (a->size < 2)
		return (0);
	buff = a->stack[0];
	i = -1;
	while (++i < a->size - 1)
		a->stack[i] = a->stack[i + 1];
	a->stack[i] = buff;
	write(fd, "ra\n", 3);
	return (1);
}

int	rb(t_stack *b, int fd)
{
	if (b->size < 2)
		return (0);
	ra(b, 10);
	write(fd, "rb\n", 3);
	return (1);
}

int	rr(t_stack *a, t_stack *b, int fd)
{
	ra(a, 10);
	ra(b, 10);
	write(fd, "rr\n", 3);
	return (1);
}
