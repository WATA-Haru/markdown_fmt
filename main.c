#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h> //for test

static int		between_vertical_len(const char *str);
static char	*allocate_elm(const char *str);
static char	*strtrim(const char *s1, const char *set);

typedef struct s_cell
{
	char							*element;
	int								len;
	int								x;
	int								y;
	struct s_cell			*next;
}								t_cell;

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
	// |で区切られていなかった場合のエラーハンドリング
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

static char	*strtrim(const char *s1, const char *set)
{
	char	*trimed_str;
	size_t	s1_len;
	size_t	i;
	size_t	j;

	if (!s1)
		return NULL;
	s1_len = strlen(s1);
	if (!set)
		return strdup(s1);
	i = 0;
	j = s1_len - 1;
	while (s1[i] && strchr(set, s1[i]))
		i++ ;
	if (i == s1_len)
		return strdup("\0");
	while (j > i && (strchr(set, s1[j])))
		j-- ;
	trimed_str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (trimed_str == NULL)
		return NULL;
	memcpy(trimed_str, &s1[i], j - i + 1);
	trimed_str[j - i + 1] = '\0';
	return trimed_str;
}

int test ()
{
	char input0[] = "| header1 | header2 |\n"
									"| ------- | --- |\n"
									"| 1  | 2          |\n"
									"| 3     | 4 |";
	char basic[] = "|      header1    | header2 |\n";
	char one_char[] = "|h| header2 |\n";
	char no_char[] = "|| header2 |\n";
	char error_case[] = "|\n";

	// between_vertical_len tests
  assert(between_vertical_len(basic) == 17);
  assert(between_vertical_len(one_char) == 1);
  assert(between_vertical_len(no_char) == 0);
  assert(between_vertical_len(error_case) == -1);
  assert(between_vertical_len(NULL) == -1);
	
	// allocate_elm tests
	// strtrim test
	char *alc_tmp;
	char *trim_tmp;
	alc_tmp = allocate_elm(input0);
	trim_tmp = strtrim(alc_tmp, " ");
	printf("alc  input_0: %s, len: %zu\n", alc_tmp, strlen(alc_tmp));
	printf("trim input_0: %s, len: %zu\n", trim_tmp, strlen(trim_tmp));
	free(alc_tmp);
	free(trim_tmp);

	alc_tmp = allocate_elm(basic);
	trim_tmp = strtrim(alc_tmp, " ");
	printf("alc  basic: %s, len: %zu\n", alc_tmp, strlen(alc_tmp));
	printf("trim basic: %s, len: %zu\n", trim_tmp, strlen(trim_tmp));
	free(alc_tmp);
	free(trim_tmp);

	alc_tmp = allocate_elm(no_char);
	trim_tmp = strtrim(alc_tmp, " ");
	printf("alc  no_char: %s, len: %zu\n", alc_tmp, strlen(alc_tmp));
	printf("trim no_char: %s, len: %zu\n", trim_tmp, strlen(trim_tmp));
	free(alc_tmp);
	free(trim_tmp);

	alc_tmp = allocate_elm(error_case);
	trim_tmp = strtrim(alc_tmp, " ");
	printf("alc  error_case: %s\n", alc_tmp);
	printf("trim error_case: %s\n", trim_tmp);
	free(alc_tmp);
	free(trim_tmp);

	// NULL strtrim is tested
	printf("null_case: %s\n", allocate_elm(NULL));

	// input struct
	
  return 0;
}

//int	main(void)
//{
//	test();
//	return 0;
//}

// tmp function allocate struct
int	main(void)
{
//	char input[] = "| header1 | header2 |\n"
//									"| ------- | --- |\n"
//									"| 1  | 2          |\n"
//									"| 3     | 4 |";
	char input[] = "|             artist name|    url|\n"
									"| --- | ------ |\n"
									"|Tame Impala                  | https://tameimpala.com/        |\n"
									"|     cocteau twins|  https://cocteautwins.com        |\n"
									"|Fishmans|                               http://www.fishmans.jp/                             |";
	int				i = 0;
	int				x = 0;
	int				y = 0;
	char			*original;
	char			*trimmed;
	t_cell		*cell = NULL;
	t_cell		**pp;

	pp = &cell;
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
				//todo: lstclear
				return -1;
			}
			trimmed = strtrim(original, " ");
			free(original);
			if (!trimmed)
			{
				//todo: lstclear
				return -1;
			}

			*pp = (t_cell *)malloc(sizeof(t_cell));
			if ((*pp) == NULL)
			{
				//todo: lstclear
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

	// markdown outputter

	//while (cell)
	//{	
	//	printf("====== elements =======\n");
	//	printf("cell->element: %s\n", cell->element);
	//	printf("cell->len: %d\n", cell->len);
	//	printf("cell->x: %d\n", cell->x);
	//	printf("cell->y: %d\n", cell->y);
	//	printf("cell->next: %p\n", cell->next);
	//	cell = cell->next;
	//}

	int		maxlen = 0;
	int		endx = 0;
	t_cell			*save_start;
	save_start = cell;

	//calc maxlen
	while (cell)
	{	
		if (cell->len > maxlen)
			maxlen = cell->len;
		if (cell->x > endx)
			endx = cell->x;
		cell = cell->next;
	}

	//TODO: markdownは最後改行の方がターミナルの出力きれいだから改行しちゃおう！
	cell = save_start;
	while (cell)
	{	
		if (cell->y == 1)
		{
			printf("| ");
			i = 0;
			while (i < maxlen)
			{
				printf("-");
				i++;
			}
			printf(" ");
			if (cell->x == endx)
			{
				printf("|");
				printf("\n");
			}
		}
		else
		{
			printf("| ");
			printf("%s", cell->element);
			i = 0;
			while (i < maxlen - (cell->len))
			{
				printf(" ");
				i++;
			}
			printf(" ");
			if (cell->x == endx)
			{
				printf("|");
				printf("\n");
			}
		}
		cell = cell->next;
	}
	return 0;
}
