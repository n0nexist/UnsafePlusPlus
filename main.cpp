/*
Unsafe++ by n0nexist
automatic c/c++ unsafe function checker
15 jan 2023
*/

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <map>
#include <string>
#include <filesystem>
#include <iostream>
#include <cstring>

using namespace std;

std::map<string, string> unsafe_dictionary;

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

bool isvalidfile(char* fpath){
    return hasEnding(fpath, ".c")||hasEnding(fpath, ".cpp");
}

void check_unsafe(char* filepath){

    if (isvalidfile(filepath)){

        /* unsafe functions*/
        unsafe_dictionary["printf"] = "level: \033[1;32m(low)\033[0;0m - \033[0;30mprintf is a standard C function for performing formatted output, it is not inherently unsafe, but it can be used in an unsafe manner. The problem with printf is that it allows for a format string vulnerability. This vulnerability occurs when user input is passed directly to the printf without proper validation, this could lead to a buffer overflow vulnerability. Additionally, if the format string is not specified correctly, it can lead to undefined behavior. Therefore, it is important to use printf and other similar functions with caution and ensure that input is properly validated and the format string is correct.\033[0;0m";
        unsafe_dictionary["sprintf"] = "level: \033[1;32m(low)\033[0;0m - \033[0;30msprintf is a standard C function for performing formatted output to a string, it is similar to printf but it writes the output to a char array instead of standard output. Just like printf, sprintf is not inherently unsafe, but it can be used in an unsafe manner. If user input is passed directly to sprintf without proper validation, it could lead to a buffer overflow vulnerability. Additionally, if the format string is not specified correctly, it can lead to undefined behavior. Because sprintf writes the output to a char array, it can be even more dangerous than printf when not used carefully, as a buffer overflow can be used to exploit the program.\n\nIt is important to ensure that the size of the buffer passed to sprintf is large enough to hold the output, and to validate user input before passing it to sprintf. It is generally recommended to use more secure alternatives such as snprintf, which includes a parameter for specifying the size of the buffer, which helps prevent buffer overflow vulnerabilities.\033[0;0m";
        unsafe_dictionary["strcat"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mThe strcat() function is a standard C function for concatenating two strings, it is considered unsafe because it doesn't check the size of the destination buffer before concatenating the strings, which can result in a buffer overflow vulnerability if the destination buffer is not large enough to hold the concatenated strings. In C++ there are more secure alternatives such as the += operator or the std::string::append() method for concatenating strings, which will resize the buffer if it runs out of space.\nIt is recommended to use the std::string::append() instead, which also gives you more control over the concatenation process.\n\nIt is important to always ensure that the destination buffer is large enough to hold the concatenated strings and validate the input before passing it to the strcat() function to prevent buffer overflow vulnerabilities. \033[0;0m";
        unsafe_dictionary["strcpy"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mThe strcpy() function is a standard C function for copying a string, it is considered unsafe because it doesn't check the size of the destination buffer before copying the string, which can result in a buffer overflow vulnerability if the destination buffer is not large enough to hold the source string.\n\nThe function does not check the size of the destination buffer and can cause a buffer overflow if the destination buffer is not large enough to hold the source string, this can lead to undefined behavior, program crash or even allow an attacker to execute arbitrary code by overwriting the memory.\n\nIt is recommended to use the strncpy() or strlcpy() instead, which also gives you more control over the copy process. These functions take an additional parameter that specifies the maximum number of characters to copy, which can help prevent buffer overflow vulnerabilities. It is important to always ensure that the destination buffer is large enough to hold the source string and validate the input before passing it to the strcpy() function to prevent buffer overflow vulnerabilities.\033[0;0m";
        unsafe_dictionary["gets"] = "level: \033[1;3;31m(HIGH)\033[0;0m - \033[0;30mThe gets() function is a standard C function for reading a line of text from a user. It is considered unsafe because it does not check the size of the buffer that it is reading into, which can result in a buffer overflow vulnerability. It is also easily exploitable since it doesn't validate the input size and can lead to undefined behavior, program crash or even allow an attacker to execute arbitrary code by overwriting the memory.\n\nThe gets() function is also removed from the C++11 standard and later versions, due to security concerns. It is recommended to use the fgets() or std::getline() instead. These functions take an additional parameter that specifies the maximum number of characters to read, which can help prevent buffer overflow vulnerabilities. It is important to always ensure that the destination buffer is large enough to hold the input, and validate the input before passing it to the gets() function to prevent buffer overflow vulnerabilities.\033[0;0m";
        unsafe_dictionary["vsprintf"] == "level: \033[1;33m(mid)\033[0;0m - \033[0;30mvsprintf() is a standard C function for performing formatted output to a string, similar to sprintf() it writes the output to a char array instead of standard output. However, it takes an additional argument, a va_list, that allows to pass a variable number of arguments to the function.\n\nLike sprintf(), vsprintf() is not inherently unsafe, but it can be used in an unsafe manner if the format string is not specified correctly or if the size of the buffer passed to it is too small. This can lead to undefined behavior, buffer overflow vulnerabilities, and even allow an attacker to execute arbitrary code by overwriting the memory.\n\nIt is important to always ensure that the size of the buffer passed to vsprintf is large enough to hold the output, and to validate user input before passing it to vsprintf. It is generally recommended to use more secure alternatives such as vsnprintf, which includes a parameter for specifying the size of the buffer, which helps prevent buffer overflow vulnerabilities.\033[0;0m";
        unsafe_dictionary["strlen"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mstrlen() is a standard C function that returns the length of a null-terminated string. It is not inherently unsafe, but it can be used in an unsafe manner if the input string is not a null-terminated string. This can result in undefined behavior, such as reading memory past the end of the string, which can lead to a crash or even allow an attacker to execute arbitrary code by overwriting the memory.\n\nIt is important to ensure that the input string passed to strlen() is a null-terminated string and that the input is validated before passing it to the function to prevent undefined behavior.\n\nIt is generally recommended to use std::string class in C++ instead of C-style strings and use std::string::length() method to get the length of string, it internally calls strlen() but it is safer to use as std::string has more features and checks than C-style strings\033[0;0m";
        unsafe_dictionary["scanf"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mscanf() is a standard C function for reading input from a user, it is not inherently unsafe, but it can be used in an unsafe manner if the format string is not specified correctly or if the input is not properly validated. If an attacker can control the input, they can potentially exploit a format string vulnerability and execute arbitrary code, or cause a buffer overflow by providing more input than expected.\n\nIt is important to ensure that the format string passed to scanf() is correct and that the input is properly validated before passing it to the function. It is generally recommended to use more secure alternatives such as fscanf() or sscanf() which take an additional file or string argument, respectively. It is also recommended to use std::cin or std::getline() in C++ instead of scanf() as they have more features and checks than scanf().\033[0;0m";
        unsafe_dictionary["fscanf"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mfscanf() is a standard C function for reading input from a file, it is similar to scanf() but it takes an additional file argument. It is not inherently unsafe, but it can be used in an unsafe manner if the format string is not specified correctly or if the input is not properly validated. If an attacker can control the input, they can potentially exploit a format string vulnerability and execute arbitrary code, or cause a buffer overflow by providing more input than expected.\n\nIt is important to ensure that the format string passed to fscanf() is correct, that the input is properly validated before passing it to the function, and that the file pointer passed is valid and opened in the right mode. It is generally recommended to use more secure alternatives such as sscanf() which takes a string argument instead of a file pointer, and validate the input before passing it to the function.\n\nIt is also recommended to use std::ifstream in C++ instead of fscanf() as it has more features and checks than fscanf()\033[0;0m";
        unsafe_dictionary["sscanf"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30msscanf() is a standard C function for reading input from a string, it is similar to scanf() but it takes an additional string argument. It is not inherently unsafe, but it can be used in an unsafe manner if the format string is not specified correctly or if the input is not properly validated. If an attacker can control the input, they can potentially exploit a format string vulnerability and execute arbitrary code, or cause a buffer overflow by providing more input than expected.\n\nIt is important to ensure that the format string passed to sscanf() is correct, that the input is properly validated before passing it to the function, and that the string passed is valid and in the right format.\n\nIt is generally recommended to use more secure alternatives such as std::stringstream in C++ instead of sscanf() as it has more features and checks than sscanf()\033[0;0m";
        unsafe_dictionary["vscanf"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mvscanf() is a standard C function for reading input from a user, it's similar to scanf() but it takes an additional va_list argument that allows to pass a variable number of arguments to the function. It is not inherently unsafe, but it can be used in an unsafe manner if the format string is not specified correctly or if the input is not properly validated. If an attacker can control the input, they can potentially exploit a format string vulnerability and execute arbitrary code, or cause a buffer overflow by providing more input than expected.\n\nIt is important to ensure that the format string passed to vscanf() is correct, that the input is properly validated before passing it to the function, and that the variable argument passed is valid and in the right format.\n\nIt is generally recommended to use more secure alternatives such as vfscanf() or vsscanf() which takes an additional file or string argument, respectively. It is also recommended to use std::cin or std::getline() in C++ instead of vscanf() as they have more features and checks than vscanf().\033[0;0m";
        unsafe_dictionary["vsscanf"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mvsscanf() is a standard C function for reading input from a string, it is similar to sscanf() but it takes an additional va_list argument that allows to pass a variable number of arguments to the function. It is not inherently unsafe, but it can be used in an unsafe manner if the format string is not specified correctly or if the input is not properly validated. If an attacker can control the input, they can potentially exploit a format string vulnerability and execute arbitrary code, or cause a buffer overflow by providing more input than expected.\n\nIt is important to ensure that the format string passed to vsscanf() is correct, that the input is properly validated before passing it to the function, and that the string passed is valid and in the right format, and that the variable argument passed is valid and in the right format.\n\nIt is generally recommended to use more secure alternatives such as std::stringstream in C++ instead of vsscanf() as it has more features and checks than vsscanf().\033[0;0m";
        unsafe_dictionary["vfscanf"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mvfscanf() is a function in the C standard library for reading formatted input from a stream, similar to the more commonly used fscanf function. In general, using any of the \"f\" functions for input and output (fprintf, fscanf, etc.) can be unsafe if the programmer does not properly validate the input and ensure that the output buffer is large enough to hold the data. If a user provides input that is longer than the buffer, it can cause a buffer overflow and potentially lead to a security vulnerability. It is important to validate input and use secure coding practices when using these functions.\033[0;0m";
        unsafe_dictionary["realpath"] = "level: \033[1;33m(mid)\033[0;0m - \033[0;30mThe realpath() function in C is used to resolve a pathname, and can be used to convert a relative pathname to an absolute pathname. In general, the realpath() function itself is not vulnerable, however the way it's used can lead to vulnerabilities if not used carefully.\n\nOne potential issue is that the realpath() function can be used to resolve symbolic links, and if an attacker is able to manipulate the symbolic link, it can cause the program to access unintended files or directories. This can lead to privilege escalation or information leakage vulnerabilities.\n\nAnother potential issue is that realpath() function may allocate memory dynamically, and if the program does not properly check the return value of the function, it can lead to a null pointer dereference.\n\nIt's important to validate the input passed to the realpath() function, and check the return value to ensure that the pathname is valid and the buffer passed to the function is large enough to hold the resolved pathname.\033[0;0m";
        /* unsafe functions*/
        
        ifstream file(filepath);
        if (file.is_open()) {
            string line;
            int linecounter = 0;

            while (getline(file, line)) {
                linecounter++;

                for (auto const& x : unsafe_dictionary) {
                    if (line.find(" "+x.first+"(") != string::npos||line.rfind(x.first+"(", 0) == 0) {
                        cout << "* " << x.first << " found at line " << linecounter << " on file \033[0;46m\033[0;47m" << filepath << "\033[0;0m" << endl;
                        cout << "(" << x.second << ")\n\n";
                    }
                }

            }
            file.close();
        } else {
            cout << "Error while opening " << filepath << " - Exiting." << endl;
            exit(1);
        }
    }
}

int main(int argc, char** argv) {
    
    cout << "\033[0;0m\033[1;36m _     _      __    __    ____  ____ ++"<<endl;
    cout << "| | | | |\\ | ( (`  / /\\  | |_  | |_    "<<endl;
    cout << "\\_\\_/ |_| \\| _)_) /_/--\\ |_|   |_|__   \033[0;0m"<<endl;

    if (argc!=2){
        cout << "Usage: " << argv[0] << " (file/directory)" << endl;
    }

    cout << "Checking if " << argv[1] << " exists and it's file type.." << endl;

    struct stat s;
    if (stat(argv[1], &s) == 0) {
        if (s.st_mode & S_IFDIR) {
            cout << argv[1] << " - directory" << endl;
            
            using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

            for (const auto& dirEntry : recursive_directory_iterator(argv[1])){
                string str = dirEntry.path().string();
                char* c = strcpy(new char[str.length() + 1], str.c_str());
                check_unsafe(c);
            }

        } else if (s.st_mode & S_IFREG) {
            cout << argv[1] << " - file" << endl;
            if (isvalidfile(argv[1])){
                check_unsafe(argv[1]);
            }else{
                cout << "Files must end with .c/.cpp extension." << endl;
                exit(0);
            }
        } else {
            cout << argv[1] << " - unknown" << endl;
            exit(0);
        }
    } else {
        cout << "Stat failed for " << argv[1] << " - Maybe it was removed?"<< endl;
        exit(0);
    }

}