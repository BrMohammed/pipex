# ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void creat_fille(char *argv);
int open_file(char *argv);
char	*ft_strnstr(const char *str, const char *find, size_t slen);
int	ft_strcmp( const char *s1, const char *s2);

#endif