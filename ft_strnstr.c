#include "pipex.h"

char	*ft_strnstr(const char *str, const char *find, size_t slen)
{
	size_t	n;
	size_t	k;

	k = 0;
	n = 0;
	if (find[k] == '\0')
		return ((char *)str);
	if (slen == 0)
		return (NULL);
	while (str[k] != '\0' && k <= slen)
	{
		if (find[n] == str[k])
		{
			while (str[k + n] == find[n] && find[n] != '\0')
				n++;
			if (find[n] == '\0' && (n + k) <= slen)
				return ((char *)&str[k + 5]);
		}
		n = 0;
		k++;
	}
	return (0);
}