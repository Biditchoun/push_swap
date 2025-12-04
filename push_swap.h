/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 17:00:11 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

int	main(int ac, char **av);
int	check_argssize(int ac, char **av);
int	*convert_to_arr(char **av, int argssize);
int	check_if_sorted(t_stack *a);
int	bubble_sort(t_stack *a);
int	sort_this_shit(t_stack *a, t_stack *b, t_stack *index);

int	sa(t_stack *a, int fd);
int	sb(t_stack *b, int fd);
int	ss(t_stack *a, t_stack *b, int fd);
int	pa(t_stack *a, t_stack *b, int fd);
int	pb(t_stack *a, t_stack *b, int fd);
int	ra(t_stack *a, int fd);
int	rb(t_stack *b, int fd);
int	rr(t_stack *a, t_stack *b, int fd);
int	rra(t_stack *a, int fd);
int	rrb(t_stack *b, int fd);
int	rrr(t_stack *a, t_stack *b, int fd);

#endif

/*typedef struct	s_stack
{
	int		nb;
	int		place;
	t_stack	*next;
	t_stack	*prev;
}	t_stack;*/
