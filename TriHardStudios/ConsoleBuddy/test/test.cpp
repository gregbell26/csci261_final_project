#define CONSOLE_BUDDY_LIB
#include <ConsoleBuddy/ConsoleBuddy.h>

#include <iostream>

int main(){

    THS::Console* console = THS::initalizeConsole();

    THS::test(console);

    std::cin.get();


    delete console;
    return 0;
}