#include "markdown_fmt.h"

char			*strtrim(const char *s1, const char *set);
void			free_all_cell(t_cell **cell);

char	*strtrim(const char *s1, const char *set)
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

void		free_all_cell(t_cell **cell)
{
	t_cell		*tmp;

	if (!cell || !*cell)
		return ;
	while (*cell)
	{
		tmp = (*cell)->next;
		free((*cell)->element);
		free(*cell);
		*cell = tmp;
	}
}
