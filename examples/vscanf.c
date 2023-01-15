/*
vscanf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>
#include <stdarg.h>

void GetMatches( const char * format, ... )
{
  va_list args;
  va_start (args, format);
  vscanf (format, args); // buffer overflow
  va_end (args);
}

int main ()
{
    /*
    Exploit:
    "Please enter a number and a word:" 3 rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
    */

  int val;
  char str[30]; // the buffer

  printf ("Please enter a number and a word: ");
  fflush (stdout);
  GetMatches ("%d %s", &val, str); // no lenght checks = vulnerable
  printf ("Number read: %d\nWord read: %s\n", val, str);

  return 0;
}