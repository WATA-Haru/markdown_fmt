#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h> //for test

//typedef struct s_token
//{
//	char			*element;
//	int				len;
//	int				x;
//	int				y;
//	s_token		*next;
//}								t_token;
//

static int		between_vertical_len(const char *str)
{
	int		i = 0;
	int		start_flag = false;
	int		start = 0;
	int		end = 0;

	if (!str)
		return (-1);
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
		return (-1);
	return (end - start - 1);
}

static char	*allocate_elm(const char *str)
{
	char	*elmstart_ptr;
	char	*original;
	int		len = 0;

	if (!str)
		return (NULL);
	len = between_vertical_len(str);
	if (len < 0)
		return (NULL);
	original = (char *)calloc(sizeof(char), (len + 1));
	if (!original)
		return (NULL);
	elmstart_ptr = (char *)++str;
	for(int i = 0; i < len; i++)
	{
		original[i] = *elmstart_ptr;
		elmstart_ptr++;
	}
	return original;
}

int test ()
{
	char input0[] = "| header1 | header2 |\n"
									"| ------- | --- |\n"
									"| 1  | 2          |\n"
									"| 3     | 4 |";
	// between_vertical_len tests
	char basic[] = "| header1 | header2 |\n";
	char one_char[] = "|h| header2 |\n";
	char no_char[] = "|| header2 |\n";
	char error_case[] = "|\n";
  assert(between_vertical_len(basic) == 9);
  assert(between_vertical_len(one_char) == 1);
  assert(between_vertical_len(no_char) == 0);
  assert(between_vertical_len(no_char) == 0);
  assert(between_vertical_len(error_case) == -1);
  assert(between_vertical_len(NULL) == -1);
	//printf("%s\n", basic);
	//printf("%d\n", between_vertical_len(basic));
	
	// allocate_elm tests
	printf("input_0: %s\n", allocate_elm(input0));
	printf("basic: %s\n", allocate_elm(basic));
	printf("no_char: %s\n", allocate_elm(no_char));
	printf("error_case: %s\n", allocate_elm(error_case));
	printf("null_case: %s\n", allocate_elm(NULL));
	
  return 0;
}

int	main(void)
{
	test();
	return 0;
}
