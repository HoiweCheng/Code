#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *buf = (char*)malloc(sizeof(char));
    char *input = "parallelli";
    int ret = snprintf(buf, 7, "%s", input);
    //ret is the return value of snprintf(), == size of input str (10 this case);
    printf("ret = %d, buf = %s\n", ret, buf);
    return 0;
}
