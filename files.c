#include "pipex.h"

void creat_fille(char *argv)
{
    int output;

    output = open(argv,O_RDWR | O_CREAT,0777);
    dup2(output,1);
    close(output);
}
int open_file(char *argv)
{
    int input;
    input =  open(argv,O_RDWR ,0777);
    dup2(input,0);
    close(input);
    return(input);
} 