/*
sscanf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>


int main (int argc, char** argv) {


    /*
    Exploit:
    ./example aaaaaaaaa
    */
   
    char hello[8]; // the buffer

    sscanf(argv[1], "%s", &hello); // no lenght checks = vulnerable

}