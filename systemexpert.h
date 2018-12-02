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


typedef struct          s_expert
{
    char                alpha;
    int                 status;
    int                 f_facts;
    struct s_expert     *next;
}                       t_expert;


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
int checking(int fd, t_def **link, char ***s);
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
void check_s(char ***s);
t_expert *add_exp(t_expert *list, char c, int i);
void prepare(t_expert **exp,  t_def	*list);
void print_exp(t_expert *exp);


 int             is_alpha(char c);
  int             alpha_amb(t_expert *head, char alpha);
  int                 edit_value(t_expert **head, char alpha, int status, int amb);
  int                 alpha_status(t_expert *head, char alpha);
//static int      or_exist(char *line);
//static int             check_truth(t_expert **head, char *first, int back_truth, int fuck);
//static int     break_into_two(char *line, char **first, char **last);
//static int     make_true(t_expert **head, char *line, char *first, int prev_amb);
//static int      prev_amb(char *line, t_expert *head);
void            algo(t_expert **head, char **rules);
#endif
