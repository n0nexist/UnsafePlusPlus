/*
vfscanf example from
github.com/n0nexist/UnsafePlusPlus
*/


#include <stdio.h>
#include <stdarg.h>

void ReadStuff (FILE * stream, const char * format, ...)
{
  va_list args;
  va_start (args, format);
  vfscanf (stream, format, args); // buffer overflow
  va_end (args);
}

int main ()
{

    /*
    Exploit:
    put this string inside of myfile.txt
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    and launch the code
    */


  FILE * pFile;
  int val;
  char str[100]; // the buffer

  pFile = fopen ("myfile.txt","r");

  if (pFile!=NULL) {
    ReadStuff ( pFile, " %s %d ", str, &val ); // no lenght checking = vulnerable
    printf ("I have read %s and %d", str, val);
    fclose (pFile);
  }

  return 0;
}