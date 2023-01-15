/*
strlen example from
github.com/n0nexist/UnsafePlusPlus
*/



int main(int argc, char** argv){
    

    /*
    unsigned short max value = 65535
    a string with 65600 chars for example,
    will pass this check.
    */

    unsigned short len = strlen(argv[1]);

    if(len >= 100)
    {
        printf("you did not pass the check");
    }

    printf("you passed the check!");


}