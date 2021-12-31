# ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
#include <sys/wait.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void creat_fille(char *argv);
void open_file(char *argv);

#endif