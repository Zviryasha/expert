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
	t_def *list;
	t_expert *exp;
	char **s;

	s = NULL;
	exp = NULL;
	list = NULL;
	if (ac == 2)
	{
		printf("_____--------- %s --------_______\n", av[1]);
		if (redable(av[1]) == 0)
		{
			printf("Not readable file\n");
			return (0);
		}
		checking(redable(av[1]), &list, &s);   // peredayu fd v checking
		check_s(&s);
		if (ck_rules(s) == 0) // chening rules
			return (0);
		prepare(&exp, list);
		algo(&exp, s);
	//	print_exp(exp);
	//	check_list(list);
		printf("\033[1;33m"); 
		printf("valid input\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m"); 
		printf("Not valid intup\n");
		printf("\033[0m");
	}
}
