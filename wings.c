/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wings.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:39:17 by opanchen          #+#    #+#             */
/*   Updated: 2018/12/02 12:39:19 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "systemexpert.h"

t_expert *add_exp(t_expert *list, char c, int i)
{
	t_expert *tmp;

	tmp = malloc(sizeof(t_expert));
	if (tmp)
	{
		tmp->alpha = c;
		tmp->status = i;
		tmp->f_facts = 0;
		tmp->next = list;
	}
	return tmp;
}


void prepare(t_expert **exp,  t_def	*list)
{
	while (list)
	{
		(*exp) = add_exp(*exp, list->c, list->i);
		list = list->next;
	}
}


void print_exp(t_expert *exp)
{
	while (exp)
	{
		printf("alpha = %c\n", exp->alpha);
		printf("is true =  %d\n", exp->status);
		printf("ambiouts =  %d\n", exp->f_facts);
		exp = exp->next;
	}
}


void check_s(char ***s)
{
	int i;
	int j;
	char **t;
	char *e;

	i = -1;
	while ((*s)[++i] != NULL)
	{
		j = -1;
		while ((*s)[i][++j] != '\0')
		{
			if ((*s)[i][j] == '\t')
				(*s)[i][j] = ' ';
		}
	}
	i = -1;
	while ((*s)[++i] != NULL)
	{
		t = ft_strsplit((*s)[i], ' ');
		e = ft_strnew(100);
		
		j = 0;
		while (t[j] != NULL)
		{
			e = ft_strjoin(e, t[j]);
			j++;
		}
		free((*s)[i]);
		(*s)[i] = ft_strnew(ft_strlen(e) + 1);
		ft_strcpy((*s)[i], e);
		free(e);
	}
}
