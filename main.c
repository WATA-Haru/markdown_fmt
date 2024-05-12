#include "markdown_fmt.h"

int	main(void)
{
	char ex00[] = "| header1 | header2 |\n"
										"| ------- | --- |\n"
										"| 1  | 2          |\n"
										"| 3     | 4 |";
	char ex01[] = "| header1 | header2 |\n"
								"|------ | --- |\n"
								"| 1  |          |\n"
								"| 3     | 4 |";
	char ex02[] = "|             artist name|    url|\n"
										"| --- | ------ |\n"
										"|Tame Impala                  | https://tameimpala.com/        |\n"
										"|     cocteau twins|  https://cocteautwins.com        |\n"
										"|Fishmans|                               http://www.fishmans.jp/                             |";
	char ex03[] = "| header1 | header2 | header 3 |\n"
								"|------ | --- | -|\n"
								"| 1  |          | |\n"
								"| 3     | 4 |hoge|";
	t_cell		*cell;

	if (create_cell(ex00, &cell) == -1)
		return (-1);
	printf_markdown(cell);
	free_all_cell(&cell);
	printf("\n");

	if (create_cell(ex01, &cell) == -1)
		return (-1);
	printf_markdown(cell);
	free_all_cell(&cell);
	printf("\n");

	if (create_cell(ex02, &cell) == -1)
		return (-1);
	printf_markdown(cell);
	free_all_cell(&cell);
	printf("\n");

	if (create_cell(ex03, &cell) == -1)
		return (-1);
	printf_markdown(cell);
	free_all_cell(&cell);
	printf("\n");
	return (0);
}

//int test ()
//{
//	char input0[] = "| header1 | header2 |\n"
//									"| ------- | --- |\n"
//									"| 1  | 2          |\n"
//									"| 3     | 4 |";
//	char basic[] = "|      header1    | header2 |\n";
//	char one_char[] = "|h| header2 |\n";
//	char no_char[] = "|| header2 |\n";
//	char error_case[] = "|\n";
//
//	// between_vertical_len tests
//  assert(between_vertical_len(basic) == 17);
//  assert(between_vertical_len(one_char) == 1);
//  assert(between_vertical_len(no_char) == 0);
//  assert(between_vertical_len(error_case) == -1);
//  assert(between_vertical_len(NULL) == -1);
//	
//	// allocate_elm tests
//	// strtrim test
//	char *alc_tmp;
//	char *trim_tmp;
//	alc_tmp = allocate_elm(input0);
//	trim_tmp = strtrim(alc_tmp, " ");
//	printf("alc  input_0: %s, len: %zu\n", alc_tmp, strlen(alc_tmp));
//	printf("trim input_0: %s, len: %zu\n", trim_tmp, strlen(trim_tmp));
//	free(alc_tmp);
//	free(trim_tmp);
//
//	alc_tmp = allocate_elm(basic);
//	trim_tmp = strtrim(alc_tmp, " ");
//	printf("alc  basic: %s, len: %zu\n", alc_tmp, strlen(alc_tmp));
//	printf("trim basic: %s, len: %zu\n", trim_tmp, strlen(trim_tmp));
//	free(alc_tmp);
//	free(trim_tmp);
//
//	alc_tmp = allocate_elm(no_char);
//	trim_tmp = strtrim(alc_tmp, " ");
//	printf("alc  no_char: %s, len: %zu\n", alc_tmp, strlen(alc_tmp));
//	printf("trim no_char: %s, len: %zu\n", trim_tmp, strlen(trim_tmp));
//	free(alc_tmp);
//	free(trim_tmp);
//
//	alc_tmp = allocate_elm(error_case);
//	trim_tmp = strtrim(alc_tmp, " ");
//	printf("alc  error_case: %s\n", alc_tmp);
//	printf("trim error_case: %s\n", trim_tmp);
//	free(alc_tmp);
//	free(trim_tmp);
//
//	// NULL strtrim is tested
//	printf("null_case: %s\n", allocate_elm(NULL));
//
//	// input struct
//	
//  return 0;
//}
