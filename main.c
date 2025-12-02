/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 18:13:31 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	argssize;
	int	*args;

	if (ac == 1)
		return (1);
	argssize = check_argssize(ac, av);
	if (!argssize)
		return (write_rtint("Error\n", 1, 2));
	args = convert_to_arr(av, argssize);
	if (!args)
		return (write_rtint("Error\n", 1, 2));
	free(args);
	return (0);
}
