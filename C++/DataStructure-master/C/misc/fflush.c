#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int i;
    int j = 1;
    while(j < 1)
    {
        fputs("input an integer: ", stdout);
        scanf("%d", &i);
        char ch;
        while((ch=getchar())!=EOF && (ch!='\n'))
            ;
        printf("\n%d\n", i);
        j++;
    }
    return 0;
}

