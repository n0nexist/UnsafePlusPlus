/*
fscanf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {

    /*
    Exploit:
    ./example aaaaaaaaaaaaa
    */


   char str1[10]; // the buffer

   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fputs(argv[1], fp); // writes to a file with no lenght checks
   
   rewind(fp);
   fscanf(fp, "%s", str1);
   
   printf("You wrote |%s|\n", str1 ); // buffer overflow

   fclose(fp);
   
   return(0);
}