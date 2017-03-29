#include<stdio.h>
#include<string.h>
#include<assert.h>

char * myStrcpy(char *s1, const char *s2)
{
    char *s = s1;
    while((*s++ = *s2++)!=0);
    return s1;
}

int main(int argc, char **args)
{
    assert(argc>=2);
    printf("argc = %d\n", argc);
    printf("%s\n%s\n", args[1],args[2]);
    myStrcpy(args[1], args[2]);
    printf("%s\n%s\n", args[1],args[2]);
    return 0;
}
