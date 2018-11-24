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

void delet_def(t_def **list, t_def *w)
{
	int i;

	i = 0;
	while (list->next)
	{
		if (list->next->)
	}
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
				*list = add_link(*list, s[i][j]);
			}
		}
	}
}

void check_list(t_def *list)
{
	t_def	*l;
	t_def	*y;
	t_def	*w;
	int		c;

	y = list;
	w = NULL;
	printf("Normal list -------\n");
	print_list(list);	
	printf("\nNormal list -------\n");
	while (list)
	{
		l = list;
		c  = 0;
		while (l)
		{
			if (list->c == l->c)
				c++;
			l = l->next;
		}
		if (c > 1)
		{
			w = add_link(w, list->c);
		//	printf("LOOOOOOOOOOOOOOL = %s\n", list->str);
		}
		list = list->next;
	}
	printf("dublicates list -------\n");
	print_list(w);
	printf("\ndublicates list -------\n");
	delet_dub(&list, w);
}