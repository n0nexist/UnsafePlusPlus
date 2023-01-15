/*
scanf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h> 
#include <stdlib.h>

int main(void) {

    char hello[30]; // the buffer

    /*
    Exploit:
    "Type something:" aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */

    printf("Type something: ");
    scanf("%s", hello); // no lenght checks = vulnerable
}