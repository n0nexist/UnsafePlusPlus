/*
vsscanf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void sfind( char* string, char* format, ... )
{
    va_list arglist;

    va_start( arglist, format );
    vsscanf( string, format, arglist ); // buffer overflow
    va_end( arglist );
}

int main(int argc, char** argv)
{

    /*
    Exploit:
    ./example aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */


    char hello[30]; // the buffer

    sfind(argv[1],"%s",hello); // no lenght checks = vulnerable
    
}