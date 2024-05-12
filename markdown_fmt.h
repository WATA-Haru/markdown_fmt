#ifndef MARKDOWN_FMT_H
# define MARKDOWN_FMT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct s_cell
{
	char							*element;
	int								len;
	int								x;
	int								y;
	struct s_cell			*next;
}								t_cell;

void		printf_markdown(const t_cell *cell);
char		*strtrim(const char *s1, const char *set);
void		free_all_cell(t_cell **cell);
int			create_cell(const char *input, t_cell **cell);

#endif
