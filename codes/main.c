#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){

    uint8_t num1 = 0x1u; //  00000001
    uint8_t num2 = 0x2u; //  00000010

    printf("Num1 : %d, Num2 : %d \n", num1, num2);

    /*
        00000001    num1
        00000010    num2
        &
        00000000
    */
    printf("Binary  and  num1 & num2 : %d \n", num1 & num2);


    /*
        00000001    num1
        00000010    num2
        |
        00000011
    */
    printf("Binary or  num1 | num2 : %d \n", num1 | num2);
    

    /*
        00000001    num1
        00000010    num2        (1 1 = 0)
        |
        00000011
    */
    printf("Binary xor  num1 ^ num2 : %d \n", num1 ^ num2);


    /*
        00000001    num1
        ~
        11111110    (0 + 2 + 4 + 8 + 16 + 32 + 64 + 128) = 254
    */
    printf("Binary not[unsigned]  ~num1: %d \n", (uint8_t) ~num1);   // unsigned 


    /*
        00000001    num1
        ~
        11111110    (0 + 2 + 4 + 8 + 16 + 32 + 64 - 128) = -2
    */
    printf("Binary not[signed]  ~num1: %d \n", ~num1);   // signed 



    /*
        00000001    num1
        << 2
        00000100    4
    */
    printf("Binary left shift  num1 << 2 : %d \n", num1 << 2);  

    /*
        00000001    num1
        >> 2                right - left bit lost
        00000000    0   
    */
    printf("Binary right shift  num1 >> 2 : %d \n", num1 >> 2);   



    /*
        00000001    (1)
        << 6
        00100000
        ^     
        00000001    (num1)
        == 
        00100001
    */
    printf("Binary flip specific bit   n ^ (1 << k): %d \n", (uint8_t) (num1 ^ (1 << 6)));


    /*
        00000001    (1)
        << 6        (k)
        00100000

        00000001    (1)
        << 4        (l)
        00001000

        ------
        00100000
        |
        00001000
        = 
        00101000

        00000001    (num1)
        ^
        00101000
        =
        00101001
    */
    printf("Binary flip two specific bits   n ^ ((1 << k) | (1 << l)): %d \n", (uint8_t) (num1 ^ ((1 << 6) | (1 << 4))));

    return 0;
}