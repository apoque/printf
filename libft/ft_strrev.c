//HEADER
//
//
//
//
//
//
//
//
//


#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = (str)[i];
		(str)[i] = (str)[j];
		(str)[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
