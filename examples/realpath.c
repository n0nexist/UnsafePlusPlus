/*
realpath example for
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdlib.h>

int main(int argc, char** argv) {

    /*
    Exploit:
    ./example aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */
    
    char buf[100]; 
    char *res = realpath(argv[1], buf);
}