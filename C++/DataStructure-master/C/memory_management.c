#include<stdio.h>
#include<stdlib.h>

//in case sometimes malloc will fail, such as when system memory is not
//enought for current size needed
void *my_malloc(size_t size)
{
    void *p = malloc(size);
    
    if ( p == NULL)
    {
        fputs("Out of memeory. \n", stderr);
        exit(EXIT_FAILURE);
    }

    return p;
}

//there are two places where variables can be put in memory. stack and heap,
//stack variables are automatically freed when they go out of scope.
//Drawbacks: (1) size should be known in advance (2) stack space is very
//limited, for example, default setting for Microsoft linker it's 1M. 
//heap. You can create variables as big as OS let you do. However, the
//compiler can help you manage it automatically anymore because it does not
//knwo when you are done. malloc and free. Memory leak happens when you forget
//to relase heap memory when you are done.
//main memory segment in C++,
//code segment: the complied program, read only
//static/global segment: staic variables that are available throught the life of the program;
//Frame/Stack segment: area of memory that temporary holds arguments and variables. 
void getSum(int *p, int *sum)
{
    int s = 0;
    int sz = 20;
    for(int i = 0; i < sz; i++)
        s += *(p+i);
    *sum = s;
}
int main()
{
    int a;//stack
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 10;
    printf("%d\n", *p);
    //if do not free(p), memory leak...
    free(p);
    p = (int*)malloc(sizeof(int));
    *p = 20;
    printf("%d\n", *p);
    free(p);

    p = (int*)malloc(20*sizeof(int));
    int i = 0;
    int *sum = malloc(sizeof(int));
    for(i = 0; i < 20; i++)
        *(p+i) = 1;
    getSum(p,sum);
    printf("sum=%d\n",*sum);
    free(sum);
    free(p);
    //heap memory will relase by os when program finished.
    return 0;
}

