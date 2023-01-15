/*
sprintf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdio.h>

void greet(char *s) {
   char buf[666];
   sprintf(buf, "Hello %s!\n", s); // memory leak
   printf(buf);
}

int main(void) {

   /*
   You can make a string payload adding %x or %p until you see the desired output
   */

   greet("aaaaaa%p%p%p%p%p%p%p%p%p%p%p%p%p%p%p%p"
         "%p%p%p%p%p%p%p%0#p\x01\x02\x03\x04");
}