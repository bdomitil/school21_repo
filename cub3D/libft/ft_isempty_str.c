#include "libft.h"

int ft_isempty_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		if (str[i] != '\n')
			return (0);
	return (1);
}