#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	str_in_array(const char *s, char delimiter)
{
	unsigned int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = -1;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a] = calloc(j + 1, sizeof(char));
			strncpy(arr[a], s - j, j);
		}
	}
	return (arr);
}

int find_max(char **str)
{
    int res = 0;

    for (int i = 0; str[i]; i++)
        if (res < strlen(str[i]))
            res = strlen(str[i]);
    return (res);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int idx = 0;
    char **split = ft_split(av[1], 32);
    int max = find_max(split);
    for (int i = 0; split[i]; i++) {
        if (i == 0) {
            for (int i = 0; i < max + 4; i++)
                printf("*");
            printf("\n");
        }
        printf("* %s", split[i]);
        for (int j = 0; j < (max - strlen(split[i]) + 1); j++)
            printf(" ");
        printf("*\n");
        if (split[i + 1] == NULL) {
            for (int i = 0; i < max + 4; i++)
                printf("*");
            printf("\n");
        }
    }
    for (int can = 0; split[can]; can++)
        free(split[can]);
    free(split);
}

// ./frame "Hello World in a frame"
// *********
// * Hello *
// * World *
// * in    *
// * a     *
// * frame *
// *********