#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/helper.h"
#include <math.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
        printf("\n");
    }
}

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    printf("y= %d\n",*y);
    *x = *x ^ *y;
    printf("x= %d\n",*x);
    *y = *x ^ *y;
    printf("y= %d\n",*y);

}


void char2int() {
    char var[] = "123";
    int i = atoi(var);
    printf("ret: %d\n",i);
}

typedef enum {
    READY  ,
    NOT_READY ,
    YES_READY,
    OTHER_STATS,
    OTHER_STATS_2,
} Stats;

enum COLOR{
    RED,
    BLUE
};

struct Test{
    int a;
    int age;
    char name[20];

};


int main() {
    short x = 12345;    //0011000000111001
    short mx = -x;      //1100111111000111  //-12345的补码
    show_bytes((byte_pointer) &x, sizeof(short));   // 39 30    小端
    show_bytes((byte_pointer) &mx, sizeof(short));  // C7 CF    小端

    unsigned short umx = (unsigned short) mx;
    printf(" %d, %u\n", mx, umx);

    printf("-------------------------------\n");

    int val = 0x87654321;
    byte_pointer valp = &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    int a = 5;
    int b = 6;
    inplace_swap(&a,&b);
    printf("%d  %d\n",a,b);

    // 打印日志
    char msg[] = "bravewinters";

    printf("msg: %s\n",msg);

    char2int();
    char buf[] = "zhangjunpu";
    printf("buf size: %llu\n", sizeof(buf));
    /*memcpy(ch,arr, sizeof(arr));
    int ret = atoi(ch);
    printf("ret:%d\n", ret);*/

    log("hello wintersweett");
    typedef struct Test T;
    T test;
    T *ptr_test = malloc(sizeof(struct  Test));

    char* mem = malloc(100 * sizeof(char));

    ptr_test->age = 18;
    ptr_test->a = 50;
    memcpy(ptr_test->name,"zhangjunpu",11);

    memcpy(mem,ptr_test, sizeof(struct Test));

    printf("info : age: %d   a: %d name: %s \n",ptr_test->age,ptr_test->a,ptr_test->name);

    struct  Test *car = (struct Test *) mem;
    printf("info : age: %d   a: %d name: %s \n",car->age,car->a,car->name);

    printf("enum %d %d %d \n",READY,NOT_READY,YES_READY);
    printf("enum %d %d %d \n",RED,BLUE,50);


    return 0;
}
