/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:23:28 by opanchen          #+#    #+#             */
/*   Updated: 2018/11/13 14:23:57 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "systemexpert.h"

int allowedsymbols(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] >= 65 && s[i] <= 90)
			return (1);
		else if ((s[i] >= 60 && s[i] <= 63) || s[i] == '!' || s[i] == ')')
			return (1);
		else if (s[i] == '^' || s[i] == '|' || s[i] == '+' || s[i] == '(')
			return (1);
		else if (s[i] >= 48 && s[i] <= 57)
			return (1);
		else
			return (0);
	}
	return (1);
}

char *deletcoment(char *s)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			while (s[i] != '\0')
			{
				s[i] = '\0';
				i++;
			}
		}
		i++;
	}
	line = ft_strnew(ft_strlen(s));
	ft_strcpy(line, s);
	return (line);
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
	if (c1 == c2)
		return (1);
	else
		return (0);
}

int checkvalidy(char *line)
{
	char **s;

	s = ft_strsplit(line, ' ');
	if (line[0] == '\0')
		return (1);
	if (check_quotes(line) == 0) // checking duzki v stroke
	{
		printf("Not valid: duzki\n");
		return (0);
	}
	if (chaeck_full(s) == 0)
	{
		printf("Not validy\n");
		return (0);
	}
	return (1);
}

int checking(int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		line = deletcoment(line); // deleting comments
		if (allowedsymbols(line) == 0) // checking on allowed symbols
		{
			printf("ERROR: not allowed symbols\n");
			return (0);
		}
		if (checkvalidy(line) == 0)
		{
			printf("ERROR: Not validy = %s\n", line);
			return (0);
		}
		printf("\033[1;34m"); //Set the text to the color red.
		printf("DOOD\n"); //Display Hello in red.
		printf("\033[0m"); 	//	printf("%s\n", line);
		free (line);
	}
	return (1);
}


int		chaeck_full(char **s)
{
	int i;
	int j;

	i = -1;
	while (s[++i] != NULL)
	{
		if (s[i][0] >= 65 && s[i][0] <= 90 && s[i][1] == '\0')
		{
			printf("character = %s\n", s[i]);
		}
		else if ((s[i][0] == '+' || s[i][0] == '|' || s[i][0] == '^') && s[i][1] == '\0')
		{
			printf("operation = %s\n", s[i]);
		}
		else if (s[i][0] == '!')
		{
			printf("negative = %s\n", s[i]);
		}
		else if (ft_strcmp(s[i], "=>") == 0 || ft_strcmp(s[i], "<=>") == 0)
		{
			printf("Inmplement = %s\n", s[i]);
		}
		else if (s[i][0] == '=' || s[i][0] == '?')
		{
			j = 0;
			while (s[i][++j] == '\0')
			{
				if (s[i][++j] < 65 && s[i][++j] > 90)
				{
					printf("EROOR = %s\n", s[i]);
					return (0);
				}
			}
		}
		else
		{
			printf("ERROR = %s\n", s[i]);
			return (0);
		}
	}
	return (1);
}













































