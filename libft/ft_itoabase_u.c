//HEADER
//
//
//
//
//
//
//


#include "libft.h"

static int	ft_countdigits(uintmax_t value, char *base)
{
	int i;

	i = 0;
	while (value > 0)
	{
		i++;
		value = value / ft_strlen(base);
	}
	return (i);
}

static void	ft_fillitoa(char *str, uintmax_t l, char *base)
{
	int i;
	int k;

	i = 0;
	k = ft_countdigits(l, base);
	while (l > 0)
	{
		str[i] = base[l % ft_strlen(base)];
		l = l / ft_strlen(base);
		i++;
	}
}

char		*ft_itoabase_u(uintmax_t value, char *base)
{
	int		k;
	char	*str;

	if (value == 0)
		return ("0");
	k = ft_countdigits(value, base);
	if (!(str = ft_strnew(k)))
		return (0);
	str[k] = '\0';
	ft_fillitoa(str, value, base);
	return (ft_strrev(str));
}
