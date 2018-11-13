/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:22:32 by opanchen          #+#    #+#             */
/*   Updated: 2018/11/12 17:22:36 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "systemexpert.h"

int redable(char *s)
{
	int fd;
	DIR *d;

	fd = open(s, O_RDONLY);
	d = opendir(s);
	if (d != NULL)
	{
		printf("Its directory\n");
		return (0);
	}
	if (fd < 0)
		return (0);
	else
		return (fd);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (redable(av[1]) == 0)
		{
			printf("Not readable file\n");
			return (0);
		}
		checking(redable(av[1]));   // peredayu fd v checking
		printf("valid input\n");
	}
	else
	{
		printf("Not valid intup\n");
	}
}
