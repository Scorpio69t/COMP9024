#include <stdio.h>

int main(void) {
    int data[12] = {5, 3, 6, 2, 7, 4, 9, 1, 8};
    // baseAddress = &data;
    printf("%d  %p\n",data[0], data);   //1 int = 4 bytes => 4 = 4.4 = 16 byte 
    int v = *data + 4;
    printf("%d \n", v);  // d[0] = 5 => *d = 5 => *d + 4 = 9
    printf("%d\n", *(data + 4));   // data[4] = 7
    printf("%d\n", data[4]); //data[4]
    printf("%d\n", *(data + *(data + 3))); //*(data+3) = 2 => *(data + 2) = 6
    printf("%d\n", data[data[2]]); //data[6] = 9

}



