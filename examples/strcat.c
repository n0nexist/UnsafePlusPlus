/*
strcat example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>

int main(int argc, char** argv){

    /*
    Exploit:
    ./example aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */

    char hello[30] = "examplestring"; // the buffer

    strcat(hello, argv[1]); // no lenght checks = vulnerable

    printf("Output %s\n", hello);

}