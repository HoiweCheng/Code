#include<stdio.h>
#include<assert.h>

//naive and bad memcpy implementation
void* memcpy(void *dest, const void *src, size_t sz)
{
    char *dest0 = dest;
    assert(dest && src);
    char *p1 = (char*)dest;
    char *p2 = (char*)src;

    int cnt = 0;
    while(cnt < sz)
    {
        *p1++ = *p2++;
        cnt++;
    }
    return dest0;
}
int main(int argc, char **args)
{
    assert(argc==3);
    int sz = sizeof(void*);
    printf("%d \n", sz);//in my OS, it's 8 bytes

    char ch= 'A';
    int x = 1024;
    float f = 1e-2;

    void *ptr;
    ptr = &ch;
    printf("ch = %c\n", *(char*)ptr);
    ptr = &x;
    printf("x = %d\n", *(int*)ptr);
    ptr = &f;
    printf("%.3lf\n", *(float*)ptr);

    printf("%s %s\n", args[1], args[2]);
    memcpy(args[1],args[2],3);
    printf("%s %s\n", args[1], args[2]);
    return 0;
}

