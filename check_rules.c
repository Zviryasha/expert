/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:13:26 by opanchen          #+#    #+#             */
/*   Updated: 2018/12/02 16:13:28 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "systemexpert.h"

int ck_rules(char **s)
{
	int i;

	i = -1;
	while (s[++i] != NULL)
	{
		printf("s = %s\n", s[i]);
		if (allowedsymbols(s[i]) == 0)
			return (0);
		if (check_quotes(s[i]) == 0)
			return (0);
		delete_qz(s);
	}
	return (1);
}

void	delete_qz(char **s)
{
	int i;
	int j;
	char **r;
	char *t;

	i = -1;
	while (s[++i] != NULL)
	{
		j = -1;
		while (s[i][++j] != '\0')
		{
			if (s[i][j] == '!' || s[i][j] == '(' || s[i][j] == ')')
				s[i][j] = ' ';
		}
	}
	i = -1;
	while (s[++i] != NULL)
	{
		j = -1;
		r = ft_strsplit(s[i], ' ');
		t = ft_strnew(50);
		while (r[++j] != NULL)
		{
			t = ft_strjoin(t, r[j]);
		}
		printf("t = %s\n", t);
	}
}

int check_quotes(char *s)
{
	int i;
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == ')')
			c1++;
		if (s[i] == '(')
			c2++;
	}
	if (c1 != c2)
	{
		printf("\033[0;31mERROR:\033[0mError in quotes = %s\n", s);
		return (0);
	}
	return (1);
}

int allowedsymbols(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] >= 65 && s[i] <= 90)
			continue;
		else if (s[i] >= 60 && s[i] <= 63)
			continue;
		else if (s[i] == '!' || s[i] == ')')
			continue;
		else if (s[i] == '^' || s[i] == '|' || s[i] == '+' || s[i] == '(')
			continue;
		else if (s[i] >= 48 && s[i] <= 57)
			continue;
		else
		{
			printf("kaka = %c\n", s[i]);
			printf("\033[0;31mERROR:\033[0mNot alloved symbols in line = %s\n", s);
			return (0);
		}
	}
	return (1);
}