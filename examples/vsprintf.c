/*
vsprintf example from
github.com/n0nexist/UnsafePlusPlus
*/

#include <stdarg.h>                                                             
#include <stdio.h>                                                              
                                                                                
char fmt1 [] = "%s  %s  %s\n";                                                  
                                                                                
int main(int argc, char** argv)                                                                  
{                                                                               
   /*
   Exploit:
   ./example aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
   */

   char string[30]; // the buffer                                                   
                                                                                
   vout(string, fmt1, "Sat", "Sun", argv[1]);                                   
   printf("The string is:  %s\n", string);                                      
}                     


void vout(char *string, char *fmt, ...)                                                                                                                         
{                                                                               
   va_list arg_ptr;                                                             
                                                                                
   va_start(arg_ptr, fmt);                                                      
   vsprintf(string, fmt, arg_ptr); // no lenght checks = vulnerable;                                        
   va_end(arg_ptr);                                                             
}           