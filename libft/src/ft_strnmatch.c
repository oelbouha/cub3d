

#include "libft.h"

int	ft_strnmatch(const char *s, char *matches, char delimiter, int n)
{
	int		ret;

	ret = 1;
	while (matches)
	{
		if (ft_strncmp(s, matches, n) == 0 
			&& (*(matches + n) == delimiter || *(matches + n) == 0))
			return (ret);
		ret++;
		matches = ft_strchr(matches, delimiter);
		matches += matches != NULL;
	}
	return (0);
}