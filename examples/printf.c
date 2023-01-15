/*
printf example from
github.com/n0nexist/UnsafePlusPlus
*/

int main(int argc, char** argv){

    /*
    Example attack:
    ./example "Hello World %p %p %p %p %p %p"
    it will return the values on the stack of the computer at the moment of running the function
    */
    
    printf(argv[1]); // memory leak

}