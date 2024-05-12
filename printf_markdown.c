#include "markdown_fmt.h"

void						printf_markdown(const t_cell *cell);
static	int			find_maxlen(const t_cell *cell);
static	int			find_endx(const t_cell *cell);

void		printf_markdown(const t_cell *cell)
{
	if (!cell)
		return ;
	int						maxlen = find_maxlen(cell);
	int						endx = find_endx(cell);
	int						i = 0;

	while (cell)
	{	
		printf("| ");
		printf("%s", cell->element);
		i = 0;
		while (i < maxlen - (cell->len))
		{
			// delimitter hundling
			if (cell->y == 1)
				printf("-");
			else
				printf(" ");
			i++;
		}
		printf(" ");
		if (cell->x == endx)
		{
			printf("|");
			printf("\n");
		}
		cell = cell->next;
	}
}

static	int			find_maxlen(const t_cell *cell)
{
	int		maxlen = 0;

	while (cell)
	{
		if (cell->len > maxlen)
			maxlen = cell->len;
		cell = cell->next;
	}
	return maxlen;
}

static	int			find_endx(const t_cell *cell)
{
	int		endx = 0;

	while (cell)
	{
		if (cell->x > endx)
			endx = cell->x;
		cell = cell->next;
	}
	return endx;
}
