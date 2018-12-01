/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systemexpert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:24:49 by opanchen          #+#    #+#             */
/*   Updated: 2018/11/13 14:24:51 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEMEXPERT_H
# define SYSTEMEXPERT_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct s_def t_def;

struct s_def
{
	char	c;
	int		i;
	int		f;
	t_def	*next;
};

t_def	*add_link(t_def *list, char c);
void	print_list(t_def *list);
int allowedsymbols(char *s);
int checking(int fd, t_def **link);
int redable(char *s);
char  *deletcoment(char *s);
int check_quotes(char *s);
int		chaeck_full(char **s);
int checkvalidy(char *line, t_def **list);
void check_list(t_def *list);
void add_def(char **s, t_def **list);
int	check_dub(t_def *list, char s);
void set_true(char *line, t_def **link);
void rigth(t_def *link, char s);
void set_find(char *line, t_def **link);
void left(t_def *link, char s);

#endif
