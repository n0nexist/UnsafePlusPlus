/*
gets example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>


int main(){

    /*
    Exploit:
    ./example aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */

    char s[30]; // the buffer
    printf("Enter the string? ");  
    gets(s);  // buffer overflow + possible arbitrary code execution
    printf("You entered %s",s);  

}