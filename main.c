#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

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

int test ()
{
	char input0[] = "| header1 | header2 |\n"
									"| ------- | --- |\n"
									"| 1  | 2          |\n"
									"| 3     | 4 |"
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
	
	// 
  return 0;
}

int	main(void)
{
	test();
	return 0;
}
