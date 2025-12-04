/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:40:06 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/03 20:17:02 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *a, int fd)
{
	int	buff;

	if (a->size < 2)
		return (0);
	buff = a->stack[0];
	a->stack[0] = a->stack[1];
	a->stack[1] = buff;
	write(fd, "sa\n", 3);
	return (1);
}

int	sb(t_stack *b, int fd)
{
	if (b->size < 2)
		return (0);
	sa(b, 10);
	write(fd, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b, int fd)
{
	sa(a, 10);
	sa(b, 10);
	write(fd, "ss\n", 3);
	return (1);
}

int	pa(t_stack *a, t_stack *b, int fd)
{
	int	i;

	if (!b->size)
		return (0);
	a->size++;
	i = a->size;
	while (--i)
		a->stack[i] = a->stack[i - 1];
	a->stack[0] = b->stack[0];
	b->size--;
	i = -1;
	while (++i < b->size)
		b->stack[i] = b->stack[i + 1];
	write(fd, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b, int fd)
{
	if (!a->size)
		return (0);
	pa(b, a, 10);
	write(fd, "pb\n", 3);
	return (1);
}
