/*
strcpy example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>

int main(int argc, char** argv){

    /*
    Exploit:
    ./example aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */

    char hello[30]; // the buffer

    strcpy(hello, argv[1]); // no lenght checks = vulnerable

}