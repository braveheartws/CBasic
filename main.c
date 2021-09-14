#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
        printf("\n");
    }
}

int main() {
    short x = 12345;    //0011000000111001
    short mx = -x;      //1100111111000111  //-12345的补码
    show_bytes((byte_pointer) &x, sizeof(short));   // 39 30    小端
    show_bytes((byte_pointer) &mx, sizeof(short));  // C7 CF    小端

    unsigned short umx = (unsigned short )mx;
    printf(" %d, %u\n",mx,umx);
    return 0;
}
