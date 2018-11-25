/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:04:30 by opanchen          #+#    #+#             */
/*   Updated: 2018/11/24 14:04:33 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "systemexpert.h"

t_def *add_link(t_def *list, char c)
{
	t_def *tmp;

	tmp = malloc(sizeof(t_def));
	if (tmp)
	{
		tmp->c = c;
		tmp->next = list;
	}
	return tmp;
}

void	print_list(t_def *list)
{
	while (list)
	{
		ft_putchar(list->c);
		list = list->next;
	}
}

int check_dub(t_def *list, char s)
{
	int i;

	i = 0;
	while (list)
	{
		if (list->c == s)
			return (1);
		list = list->next;
	}
	return (0);
}

void add_def(char **s, t_def **list)
{
	int i;
	int j;

	i = -1;
	while (s[++i] != NULL)
	{
		j = -1;
		while (s[i][++j] != '\0')
		{
			if (s[i][j] >= 65 && s[i][j] <= 90)
			{
				if (check_dub(*list, s[i][j]) == 0)
					*list = add_link(*list, s[i][j]);
			}
		}
	}
}

void check_list(t_def *list)
{

	printf("Normal list -------\n");
	print_list(list);	
	printf("\nNormal list -------\n");
}