#define CONSOLE_BUDDY_LIB
#include <ConsoleBuddy/ConsoleBuddy.h>

#include <iostream>

int main(){

    // const char* tst = "\x1B[38;2;155;10;155m";
    // const char* tst2 = "\x1B[38;2;0;100;155m";


    // std::cout << tst << "This is" << tst2<<"some text" << std::endl;


    THS::Console* console = THS::initalizeConsole();

    THS::test(console);


    // delete console;
    return 0;
}