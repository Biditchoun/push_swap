/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 19:37:40 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack *a)
{
	if (a->size == 1)
		return (0);
	if (a->size == 2 && a->stack[0] > a->stack[1])
		sa(a, 1);
	if (a->size == 2
		|| (a->stack[0] < a->stack[1] && a->stack[1] < a->stack[2]))
		return (0);
	if (a->stack[0] > a->stack[1])
	{
		if (a->stack[0] > a->stack[2] && a->stack[1] < a->stack[2])
			return (ra(a, 1) - 1);
		sa(a, 1);
		if (a->stack[0] > a->stack[2])
			rra(a, 1);
		return (0);
	}
	if (a->stack[0] > a->stack[2])
		return (rra(a, 1) - 1);
	sa(a, 1);
	ra(a, 1);
	return (0);
}

int	sort_four(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	sort_three(a);
	if (b->stack[0] > a->stack[1] && b->stack[0] < a->stack[2])
	{
		ra(a, 1);
		pa(a, b, 1);
		sa(a, 1);
		return (rra(a, 1) - 1);
	}
	pa(a, b, 1);
	if (a->stack[0] < a->stack[1])
		return (0);
	if (a->stack[0] < a->stack[2])
		return (sa(a, 1) - 1);
	ra(a, 1);
	return (0);
}

int	sort_five(t_stack *a, t_stack *b)
{
	pb(a, b, 1);
	sort_four(a, b);
	if (b->stack[0] > a->stack[1] && b->stack[0] < a->stack[2])
	{
		ra(a, 1);
		pa(a, b, 1);
		sa(a, 1);
		return (rra(a, 1) - 1);
	}
	if (b->stack[0] > a->stack[2] && b->stack[0] < a->stack[3])
	{
		rra(a, 1);
		pa(a, b, 1);
		ra(a, 1);
		return (ra(a, 1) - 1);
	}
	pa(a, b, 1);
	if (a->stack[0] < a->stack[1])
		return (0);
	if (a->stack[0] < a->stack[2])
		return (sa(a, 1) - 1);
	ra(a, 1);
	return (0);
}

int	do_the_magic(t_stack *a, t_stack *b)
{
	t_stack	a_cpy;

	if (a->size < 4)
		return (sort_three(a));
	if (a->size == 4)
		return (sort_four(a, b));
	if (a->size == 5)
		return (sort_five(a, b));
	a_cpy.stack = arr_dup(a->stack, a->size);
	if (!a_cpy.stack)
		return (-1);
	a_cpy.size = a->size;
	bubble_sort(&a_cpy);
	sort_this_shit(a, b, &a_cpy);
	free(a_cpy.stack);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	args;
	t_stack	b;
	int		rt;

	if (ac == 1)
		return (1);
	args.size = check_argssize(ac, av);
	if (!args.size)
		return (write_rtint("Error\n", 1, 2));
	args.stack = convert_to_arr(av, args.size);
	if (!args.stack)
		return (write_rtint("Error\n", 1, 2));
	if (check_if_sorted(&args))
		return (rtint_free(0, args.stack));
	b.stack = malloc(sizeof(int) * args.size);
	if (!b.stack)
		return (rtint_free(-1, args.stack));
	b.size = 0;
	rt = do_the_magic(&args, &b);
	free(args.stack);
	free(b.stack);
	return (rt);
}
