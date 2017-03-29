#include<stdio.h>
#include<stdlib.h>

//key words in c: static, extern, define, const, sizeof (not keywords)
#define min(x,y) (x<y?x:y)
const int maxn = 1000;

//size of a struct
//alignment in struct
//interal padding in structures
//每种 type 的起始地址都是自己的 size 的倍数，比如 short (2Bytes),
//所以它的起始地址一定是2的倍数，对于 struct Y, int i 从1开始占4个字节，char c
//从任意地址开始占1个字节，所以到了5，但 short s
//不能从5开始，必须从6开始，才能被2整除
//64位系统中，sizeof(pointer)=8, 所以遇到 pointer 的，就要对齐8
//reference: http://blog.csdn.net/manbug/article/details/1124845
struct X
{
    short s;
    int i;
    char c;
};

struct Y
{
    int i;
    char c;
    short s;
};

struct Z
{
    int i;
    short s;
    char c;
};

struct W
{
    char a;
    short b;
    int c;
};

struct P1 { int a; char b; int c; char d; };
struct P2 { int a; char b; char c; int d; };
struct P3 { short a[3]; char b[3]; };
struct P4 { short a[3]; char *b[3]; };
struct P5 { struct P2 *a1; char b; struct P1 a[2];  };
struct P6 { struct P2 *a1; char b;};

void testSize()
{
    int sizeX = sizeof(struct X);//12
    int sizeY = sizeof(struct Y);//8
    int sizeZ = sizeof(struct Z);//8
    printf("size(x)=%d\n",sizeX); 
    printf("size(y)=%d\n",sizeY); 
    printf("size(z)=%d\n",sizeZ);
    
    int szW = sizeof(struct W);
    printf("%d\n", szW);

    //for P1, P2, ..., P5
    printf("sz of pointer %d\n", sizeof(char*));
    printf("%d %d %d %d %d %d\n", sizeof(struct P1),sizeof(struct P2),
            sizeof(struct P3), sizeof(struct P4), sizeof(struct
                P5),sizeof(struct P6));
    //16 12 10 32 48 16
}
//how are static variables initialized?
//the scope of a static variable is local to the block in which the variable
//is defined. but the value of the static variable persists between two
//functions calls.
int get()
{
    static int i = 1;//default initialize as 0, only once, next time when call, i
//won't be initialized again, but preserve last value
    return i++;
}
//if you have already defined global_var in another file and you want to use
//it in current file, you can write 'extern int variable_name' to refer to
//that variable and use it in current file, the same for extern function

extern int global_var;
int main()
{
    testSize();
    printf("%d %d %d\n", get(), get(), get());
//    printf("extern global var = %d\n", ++global_var);
    struct Z z;
    printf("sizeof(Z.s) = %d\n", sizeof(z.s));
    return 0;
}
