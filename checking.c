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

int checkvalidy(char *line)
{
	char **s;

	s = ft_strsplit(line, ' ');
	if (line[0] == '\0')
		return (1);
	if ((s[0][0] > 65 && s[0][0] < 90) || s[0][0] == '!' || s[0][0] == '(')
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