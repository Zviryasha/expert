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

int checking(int fd, t_def **link, char ***s)
{
	char *line;
	int i;
	
	i = 0;
	*s = (char **)malloc(sizeof(char *) * 100);
	while (get_next_line(fd, &line))
	{
		line = deletcoment(line); // deleting comments
		if (line[0] == '=')
			set_true(line, link);
		else if (line[0] == '?')
			set_find(line, link);
		else
		{
			if (line[0] != '\0')
			{
				(*s)[i] = ft_strnew(ft_strlen(line) + 1);
				ft_strcpy((*s)[i], line);
				i++;
			}
		}
		free (line);
	}
	(*s)[i] = NULL;
	return (1);
}















































