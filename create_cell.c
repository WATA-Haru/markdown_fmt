#include "markdown_fmt.h"

int					create_cell(const char *input, t_cell **cell);
static int	between_vertical_len(const char *str);
static char	*allocate_elm(const char *str);

int	create_cell(const char *input, t_cell **cell)
{
	int				i = 0;
	int				x = 0;
	int				y = 0;
	char			*original;
	char			*trimmed;
	t_cell		**pp;

	if (!input || !cell)
		return (-1);

	pp = cell;
	while (input[i])
	{
		if (input[i] == '\n') 
		{
			x = 0;
			y++;
		}
		if (input[i] == '|' && (input[i+1] != '\n') && (input[i+1] != '\0'))
		{
			original = allocate_elm(&input[i]);
			if (!original)
			{
				free_all_cell(cell);
				return -1;
			}
			trimmed = strtrim(original, " ");
			free(original);
			if (!trimmed)
			{
				free_all_cell(cell);
				return -1;
			}
			*pp = (t_cell *)malloc(sizeof(t_cell));
			if ((*pp) == NULL)
			{
				free_all_cell(cell);
				return -1;
			}
			(*pp)->element = trimmed;
			(*pp)->len = strlen(trimmed);
			(*pp)->x = x;
			(*pp)->y = y;
			(*pp)->next = NULL;
			x++;
			pp = &(*pp)->next;
		}
		i++;
	}
	return (1);
}


static int		between_vertical_len(const char *str)
{
	int		i = 0;
	int		start_flag = false;
	int		start = 0;
	int		end = 0;

	if (!str)
		return -1;
	while (str[i])
	{
		if (str[i] == '|')
		{
			if (start_flag == false)
			{
				start = i;
				start_flag = true;
			}
			else
			{
				end = i;
				break;
			}
		}
		i++;
	}
	// errro handling when | does not exist
	if (end == 0)
		return -1;
	return (end - start - 1);
}

static char	*allocate_elm(const char *str)
{
	char	*elmstart_ptr;
	char	*element;
	int		len = 0;

	if (!str)
		return NULL;
	// calc element length
	len = between_vertical_len(str);
	if (len < 0)
		return NULL;
	// allocate element size memory
	element = (char *)calloc(sizeof(char), (len + 1));
	if (!element)
		return NULL;
	// elmstart_ptr points next |(vertical-symbol) 
	// | hoge | 
	//  ^
	//  elmstart_ptr
	elmstart_ptr = (char *)&str[1];
	for(int i = 0; i < len; i++)
	{
		element[i] = *elmstart_ptr;
		elmstart_ptr++;
	}
	return element;
}


