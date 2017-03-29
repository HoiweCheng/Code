#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0

int convertToNum(char *s, int *bits)
{ int num = 0;
    while( *s != 0)
    {
        num = num * 2 + (int)(*s - '0');
        s++;
        (*bits) ++;
    }
    return num;
}

int main(int argc, char **args)
{
    assert(argc == 2);
    int bit = 0;
    int *bits = &bit;
    int num = convertToNum(args[1], bits);
    printf("num = %d bits = %d\n", num, bit);

    int x = 1<<(bit-1);
    int y = 1;
    
    bool isPalin = true;
    while(x != y)
    {
        if(!(num&x &&  num&y))
        {
            isPalin = false;
            break;
        }
        x = x >> 1;
        y = y << 1;
    }

    if(isPalin)
    {
        printf("%s is palindrome\n", args[1]);
    }
    else
        printf("%s is not palindrome\n", args[1]);
    
    return 0;
}
    
