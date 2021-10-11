#include <stdio.h>
#include <stdlib.h>

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
    return 0;
}
