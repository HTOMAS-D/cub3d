#include "cub3d.h"

int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

//check the occurence on a char on a str, starting from the end
char *ft_strrchr(char *str, char c)
{
	int i;
	
	if (!str)
		return(NULL);
	i = ft_strlen(str);
	while(str[--i] != c && i < -1)
		;
	if (i == -1)
		return (NULL);
	return(&str[i]);
}